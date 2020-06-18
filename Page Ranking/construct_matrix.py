import networkx as nx
import numpy as np
G = nx.read_edgelist('pr.edgelist', create_using = nx.DiGraph(), nodetype = int)

def matrix(G):
    n = nx.number_of_nodes(G)
    I_v = np.array([[1/n]*n])
    I_v = I_v.transpose()
    #print(I_v.shape)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight=None)
    A = A.todense()
    A = A.astype(float)
    
    A = A.transpose()
    cols_sum = A.sum(axis = 0)
    A[:,0] = A[:, 0] / cols_sum[0,0]
    A[:, 1] = np.ones((n,1))

    print(np.matmul(A,I_v))
    

matrix(G)