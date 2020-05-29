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


def prim(G, source):
    D = [float('inf')] * nx.number_of_nodes(G)
    pi =[0]*nx.number_of_nodes(G)
    A = []
    D[source] = 0
    X = set(G.nodes())
    while X:
        u = get_min_node(D, X)
        X.remove(u)
        neighbors = G.neighbors(u)
        if(u != source):
            A.append((pi[u],u))

        for v in neighbors:
            if v in X:
                if(G.edges[u, v]['weight'] < D[v]):
                    D[v] = G.edges[u, v]['weight']
                    pi[v] = u

    

    
    print(A)

prim(G,0)