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
    heap = []
    heapq.heappush(heap,(0,source))

    while X:
        #min_node = get_min_node(D, X)
        min_node, min_idx = heapq.heappop(heap)
        #if overlapped entry for an node

        if(heap):
            print(heap[0])
            if(heap[0][0] > min_node):
                heapq.heappop(heap)

        X.remove(min_node)
        neighbors = G.neighbors(min_node)
        for neighbor in neighbors:
            if neighbor in X:
                heapq.heappush(heap,(neighbor, D[neighbor]))
                if(D[min_node] + G.edges[min_node, neighbor]['weight'] < D[neighbor]):
                    D[neighbor] = (D[min_node] + G.edges[min_node, neighbor]['weight'])

    
    print(D)
start = time.time()
dijkstra(G,0)

print("Elapsed time n = 10000: ", time.time() - start)



