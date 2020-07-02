#Maximum flow problem
#if there is augment path, flow can be increased
import networkx as nx
import queue
N = nx.read_weighted_edgelist('ff.edgelist', nodetype = int)


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

print(find_augmentpath(N, 0, 5))