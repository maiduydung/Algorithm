import networkx as nx
import matplotlib.pyplot as plt

#using array to check visited
check_arr = [0]*10



def helper(edgelist: str, vertex: int):
    graph = nx.read_edgelist(edgelist, nodetype = int)
    nx.draw_networkx(graph)
    plt.show()
    dfs(graph, vertex)
    

def dfs(graph ,vertex: int):
    if(check_arr[vertex] == 1):
        return
    check_arr[vertex] = 1
    print(vertex)
    for i in graph.neighbors(vertex):
        dfs(graph,i)

helper("test.edgelist",4)