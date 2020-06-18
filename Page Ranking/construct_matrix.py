import networkx as nx
import numpy as np
G = nx.read_edgelist('pr.edgelist', create_using = nx.DiGraph(), nodetype = int)

def matrix(G):
    n = nx.number_of_nodes(G)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight=None)
    A = A.todense()
    A = A.astype(float)
    print(A)

matrix(G)