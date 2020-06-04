import networkx as nx

G = nx.read_weighted_edgelist('bf.edgelist', create_using=nx.DiGraph(), nodetype= int)

def bellman_ford(G, source):
    n = nx.number_of_nodes(G)
    D = [float('inf')] * n
    D[source] = 0
    for i in range(1, n):
        #D_new = D[:]
        for u, v in G.edges():
            if (D[u] + G.edges[u,v]['weight'] < D[v]):
                D[v] = D[u] + G.edges[u,v]['weight']
        #D = D_new
    
    for u, v in G.edges():
        if(D[v] > D[u] + G.edges[u,v]['weight']):
            return (False, D)
    return (True, D)

print(bellman_ford(G, 0))