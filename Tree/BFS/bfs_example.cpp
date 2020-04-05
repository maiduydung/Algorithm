#include<iostream> 

#include <list> 
#define SIZE 6
using namespace std;

list<int>adj[100];//100 elements(node) arr of list
//0 -> a -> b -> c
//1 -> a -> b -> c
//2 -> a -> b -> c
//.. -> ..

void bfs(list<int> adj[], int src){
    cout << "\nBFS traversal\n";
    bool *visited = new bool[SIZE];
    list<int> queue;
    for(int i = 0; i < SIZE; i ++)
        visited[i] = false;//marking all verteces unvisited
    
    //mark current vertex visited and enqueue it
    visited[src] = true;
    queue.push_back(src);

    while (!queue.empty()){
        src = queue.front();//assigning so that i = adj[src].begin() can be updated below
        
        //dequeue vertex from queue
        //im only printing it just so we can see
        cout << queue.front() << " "; 
        queue.pop_front();

        
        for (auto i = adj[src].begin(); i != adj[src].end(); i++)
        {
            if (visited[*i]==false)
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void addEdge(list<int> adj[], int src, int dst){
    adj[src].push_back(dst);
    adj[dst].push_back(src);//remove this line for directed graph
}

void print_graph(list<int>queue[]){
    cout << "\nPrinting graph\n";
    for(int i = 0; i < SIZE; i++){
        cout << i << " ";
        for (auto child:queue[i])
        {
            cout << child << " ";
        }
        cout << "\n";
    }
}

int main(){
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 4, 1);

    
    bfs(adj, 1);

    print_graph(adj);
    return 0;
}
