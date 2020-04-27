import matplotlib.pyplot as plt
import networkx as nx 

check_arr = [0]*10
result = 0


def helper(edgelist:str, vertex:int):
    graph = nx.read_edgelist(edgelist, nodetype = int)
    print("degree of all verteces ", graph.degree)
    dfs(graph, vertex)
    nx.draw_networkx(graph)
    plt.show()
    print(result)
    return False if(result > 0) else True

def dfs(graph, vertex):
    #modifying global varible requires "global" keyword
    #euler cycle: every vertex has even num of degree
    global result
    if (graph.degree[vertex] % 2 != 0):
        result += 1
    if(check_arr[vertex] == 1):
        return

    
    check_arr[vertex] = 1
    for i in graph.neighbors(vertex):
        dfs(graph, i)



print(helper('user.edgelist', 0))