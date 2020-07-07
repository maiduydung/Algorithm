import networkx as nx
import queue
G = nx.read_weighted_edgelist('ff.edgelist', create_using=nx.DiGraph(), nodetype=int)

# basic intuition
# ford_fulkerson(G, s, t){
#     set FLOW = 0
#     in residue network N deduce from G
#         while there is a path from s to t (dfs for simpicity)
#         {
#             update FLOW by increasing by bottle neck value
#             let N be the residue network of G for FLOW
#         }
# }

def find_augmentpath(N, s, t):
    P = [s] * nx.number_of_nodes(N)
    visited = set()
    stack = queue.LifoQueue()
    stack.put(s)
    while (not stack.empty()):
        v = stack.get()
        if v == t:
            return (P,True)
        if not v in visited:
            visited.add(v)
            for w in N.neighbors(v):
                if (w not in visited and N.edges[v,w]['weight'] > 0):
                    stack.put(w)
                    P[w] = v
    return (P, False)

def restore_shortestpath(u, v, P):
    #basically we're just swapping u and v here
    #then append the (parent -> child) to path
    #then at the end reverse the list because if not, it'll look like (sink, parent1, parent2, ..., start)
    #we dont want that
    path = []
    temp = v
    while temp != u:
        parent = P[temp]
        path.append((parent, temp))
        temp = parent
    path.reverse()
    return path

def min_capacity(N, augment_path):
    min_cap = float('inf')
    #flag technique, nothing special
    for u, v in augment_path:
        cap = N.edges[u, v]['weight']
        if cap < min_cap:
            min_cap = cap
    return min_cap

def increase_flow(N, path, amount, flow):
  for u, v in path:
    if flow[(v, u)] <= 0:
      flow[(u, v)] += amount
    else:
      diff = flow[(v, u)] - amount
      if diff >= 0:
        flow[(v, u)] = diff
      else:
        flow[(u, v)] = -diff
        flow[(v, u)] = 0
    N.edges[u, v]['weight'] -= amount
    if N.has_edge(v, u):
      N.edges[v, u]['weight'] += amount
    else:
      N.add_edge(v, u, weight=amount)

def ford_fulkerson(G, s, t):
    N = G.copy()
    f = {} #flowing edge list
    for u, v in N.edges:
        f[(u, v)] = 0
        f[(v, u)] = 0
    P, is_found = find_augmentpath(N, s, t)
    while is_found:
        augment_path = restore_shortestpath(s, t, P)
        min_cap = min_capacity(N, augment_path)
        increase_flow(N, augment_path, min_cap, f)
        P, is_found = find_augmentpath(N, s, t)
    return N, f


s = 0
t = 5
N, f = ford_fulkerson(G, s, t)
print(f)

