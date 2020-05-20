import networkx as nx
import random

#generate random graph
G = nx.fast_gnp_random_graph(1000, 0.01)

#assign random weight to each edge
for (u,v) in G.edges():
    G.edges[u,v]['weight'] = random.randint(1,100)

#write graph to file
nx.write_weighted_edgelist(G, "random_graph.edgelist")