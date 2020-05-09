import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_weighted_edgelist('dij.edgelist', nodetype = int)

# D = [float('inf')] * nx.number_of_nodes(G)
# Unvisited = []
# for i in G.nodes():
#     Unvisited.append(i)

#print(G.edges[0, 1]['weight'])

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
    D_cal = [float('inf')] * nx.number_of_nodes(G)
    X = []
    for i in G.nodes():
        X.append(i)
    D[source] = 0
    X.remove(source)

    print("all nodes: ", G.nodes())
    while X:
        for node in G.nodes():
            for i in G.neighbors(node):
                D_cal[i] = G.edges[node, i]['weight'] + D[node]
                min_node = get_min_node(D_cal, X)
                if min_node in X:
                    if (D[i] > D_cal[i]):
                        D[i] = D_cal[i]
                        X.remove(min_node)

    for i in range(len(D)):
        print(i, " ", D[i])

    print('---------')
    print(nx.shortest_path(G,source))
dijkstra(G,1)
