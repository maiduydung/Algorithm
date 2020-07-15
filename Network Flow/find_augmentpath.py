#Maximum flow problem
#if there is augment path, flow can be increased
import networkx as nx
import queue
N = nx.read_weighted_edgelist('ff.edgelist', nodetype = int)

def find_augmentpath(G, s, t): #graph, source, sink
    P = [s] * nx.number_of_nodes(G)
    visited = set()
    stack = queue.LifoQueue()
    stack.put(s)
    while(not stack.empty()):
        v = stack.get() #pop stack
        if v == t:
            return (P, True)
        if not v in visited:
            stack.put(v)
            for w in G.neighbors(v):
                if (not w in visited) and (G.edges[v,w]['weight'] > 0):
                    stack.put(w)
                    P[w] = v # previous node of w is v

    return (P, False)

print(find_augmentpath(N, 0, 5))