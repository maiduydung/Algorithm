import networkx as nx
import numpy as np


G = nx.read_edgelist('pr.edgelist', create_using = nx.DiGraph(), nodetype = int)
    
def update(G,h0,k):
    n = nx.number_of_nodes(G)
    A = nx.adjacency_matrix(G, nodelist=range(n), weight=None)
    A = A.todense()
    A = A.astype(int)
    AT = A.transpose()
    for _ in range(k):
        ak = np.matmul(A.transpose(),h0) #authority
        ak = ak / ak.sum(axis=0)
        h0 = np.matmul(A,ak)             #hub
        h0 = h0 / h0.sum(axis=0)
        
    return (ak,h0)

h0 = np.ones((12,1))
print(update(G,h0,100))