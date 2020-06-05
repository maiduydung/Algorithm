import networkx as nx
import queue
G = nx.read_weighted_edgelist('dij.edgelist', nodetype= int)


def dfs(G, source):
    visited = set( )
    stack = queue.LifoQueue()
    stack.put(source)

    while not stack.empty():
        u = stack.get()
        if u not in visited:
            visited.add(u)
            print(u)
            for v in G.neighbors(u):
                if v not in visited:
                    stack.put(v)

dfs(G, 0)