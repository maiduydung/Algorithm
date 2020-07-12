import networkx as nx
import numpy as np

G = nx.read_edgelist("pr.edgelist", create_using = nx.DiGraph(), nodetype = int)
def transition_matrix(G):
    n = nx.number_of_nodes(G)
    #getting adjacency matrix, actually this looks like a list of every edges to me
    A = nx.adjacency_matrix(G, nodelist=range(n),weight=None)

    #now this is looking right
    A = A.todense()
    #the matrix is a object of a special class, 
    # we need to convert to float to calculate on it
    A = A.astype(float) 
    # we need to transpose and normalize then multiply 
    # with the current importance to get the page rank value
    A = A.transpose()  
    #axis = 0 col
    #axis = 1 row
    cols_sum = A.sum(axis = 0) #access with cols_sum[0,i]
    for i in range(n):
        s = cols_sum[0 , i]
        if s != 0:
            A[:,i] = A[:,i]/s #divide every element of i_th col to s
        else:
            #to achieve convergence
            A[:,i] = 1/n 
    return A

print(transition_matrix(G))
