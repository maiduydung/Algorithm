import networkx as nx
import numpy as np
G = nx.read_edgelist('pr.edgelist', create_using = nx.DiGraph(), nodetype = int)

def matrix(G):
    n = nx.number_of_nodes(G)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight=None)
    A = A.todense()
    A = A.astype(float)
    
    A = A.transpose()
    cols_sum = A.sum(axis = 0)
    A = A / cols_sum
    A[np.isnan(A)] = 1/n

    return(A)

def update(G,v,d,k):
    A = matrix(G)
    result = v
    n = nx.number_of_nodes(G)
    J = np.ones((n,n))/n
    M_G = A*d + (1-d)*J
    for i in range(k):
        result = np.matmul(M_G,result)
    return result

v = np.ones((12,1))/12
print(update(G,v,0.85,1000))

pr = nx.pagerank(G, alpha = 0.85)
print(pr)

#matrix(G)