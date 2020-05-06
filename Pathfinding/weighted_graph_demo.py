import networkx as nx
import matplotlib.pyplot as plt

G = nx.read_weighted_edgelist('dij.edgelist')
D = [float('inf')]*nx.number_of_nodes(G)

pos=nx.planar_layout(G)
nx.draw_networkx(G, pos)
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.show()