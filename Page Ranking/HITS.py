import networkx as nx
import numpy as np

G = nx.read_edgelist("pr.edgelist", create_using = nx.DiGraph(), nodetype = int)

def transition_matrix(G):
    n = nx.number_of_nodes(G)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight="weight")
    A = A.todense()
    A = A.astype(float)
    A = A.transpose()
    col_sum = A.sum(axis = 0)
    for i in range(n):
        s = col_sum[0, i]
        if (s != 0):
            A[:,i] = A[:,i] / s
        else:
            A[:,i] = 1/n
    return A

print(transition_matrix(G))