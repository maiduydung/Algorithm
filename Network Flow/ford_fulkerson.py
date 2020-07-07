import networkx as nx
import queue
N = nx.read_weighted_edgelist('ff.edgelist', nodetype = int)

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


def ford_fulkerson(G, s, t):
    N = G.copy
    f = {} #edge list
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

