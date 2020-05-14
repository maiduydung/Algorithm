import networkx as nx
import matplotlib.pyplot as plt

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
    while X:
        min_node = get_min_node(D, X)
        X.remove(min_node)
        neighbors = G.neighbors(min_node)
        for neighbor in neighbors:
            if neighbor in X:
                if(D[min_node] + G.edges[min_node, neighbor]['weight'] < D[neighbor]):
                    D[neighbor] = (D[min_node] + G.edges[min_node, neighbor]['weight'])
    

    
    print(D)

dijkstra(G,0)

