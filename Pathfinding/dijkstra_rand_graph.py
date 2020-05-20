import networkx as nx
import time
import heapq

G = nx.read_weighted_edgelist('dij.edgelist', nodetype = int)




def print_sol(D):
    for i in range(len(D)):
        print(i, " ", D[i])

def dijkstra(G, source):
    D = [float('inf')] * nx.number_of_nodes(G)
    D[source] = 0
    X = set(G.nodes())
    Heap = []

    heapq.heappush(Heap,(0, source))
    while X:
        min_node, min_idx = heapq.heappop(Heap)
        min_node = int(min_node)
        print(min_node, min_idx)
        if(Heap):
            if(Heap[0][1] == min_idx):
                heapq.heappop(Heap)

        X.remove(min_idx)
        neighbors = G.neighbors(min_idx)
        for neighbor in neighbors:
            if neighbor in X:
                if(D[min_idx] + G.edges[min_idx, neighbor]['weight'] < D[neighbor]):
                    D[neighbor] = (D[min_idx] + G.edges[min_idx, neighbor]['weight'])
                    heapq.heappush(Heap, (D[neighbor], neighbor))


    print(D)
start = time.time()
dijkstra(G,0)

print("Elapsed time n = 10000: ", time.time() - start)

