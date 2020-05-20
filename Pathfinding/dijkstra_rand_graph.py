import networkx as nx
import time
import heapq

G = nx.read_weighted_edgelist('dij.edgelist', nodetype = int)


def get_min_node(D, X):
    arg_min = -1
    min_val = float('inf')
    for i in range(len(D)):
        if D[i] < min_val:
            if i in X:
                arg_min = i
                min_val = D[i]
    return arg_min

def print_sol(D):
    for i in range(len(D)):
        print(i, " ", D[i])

def dijkstra(G, source):
    D = [float('inf')] * nx.number_of_nodes(G)
    D[source] = 0
    X = set(G.nodes())
    Heap = []
    heapq.heappush(Heap,(0,source))

    while X:
        min_node, min_idx = heapq.heappop(Heap)
        print(min_idx)
        if(Heap):
            if(Heap[0][1] == min_idx):
                heapq.heappop(Heap)


        X.remove(min_node)
        neighbors = G.neighbors(min_node)
        for neighbor in neighbors:
            if neighbor in X:
                if(D[min_node] + G.edges[min_node, neighbor]['weight'] < D[neighbor]):
                    D[neighbor] = (D[min_node] + G.edges[min_node, neighbor]['weight'])
                    heapq.heappush(Heap, (neighbor, D[neighbor]))



    print(D)
start = time.time()
dijkstra(G,0)

print("Elapsed time n = 10000: ", time.time() - start)


