import networkx as nx
import time
import heapq

G = nx.read_weighted_edgelist('random_graph.edgelist', nodetype = int)

def dijkstra_heap(G, s):
    X = set(G.nodes())
    D = [float('inf')] * nx.number_of_nodes(G)
    D[s] = 0
    Heap = []
    heapq.heappush(Heap,(0, s))

    while X:
        min_val, u = heapq.heappop(Heap)
        #if overlapped
        if(min_val != D[u]):
            continue
        X.remove(u)
        for v in G.neighbors(u):
            tmp_dst = D[u] + G.edges[u, v]['weight']
            if D[v] > tmp_dst:
                D[v] = tmp_dst
                heapq.heappush(Heap, (D[v], v))


start = time.time()
dijkstra_heap(G, 0)
print("Elapsed time n = 10000: ", time.time() - start)