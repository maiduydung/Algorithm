import networkx as nx
import numpy as np

G = nx.read_edgelist("pr.edgelist", create_using = nx.DiGraph(), nodetype = int)

def transpose_matrix(G):
    n = nx.number_of_nodes(G)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight="weight")
    A = A.todense()
    A = A.astype(float)
    A = A.transpose()
    return A


h0 = np.zeros((n ,1))


def update(G, h0, k):
    for _ in range(k):
        
