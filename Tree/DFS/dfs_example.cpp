#include<iostream>
#include<vector>
using namespace std;

vector<int>adj[100];//100 elements(node) arr of vector
//0 -> a -> b -> c
//1 -> a -> b -> c
//2 -> a -> b -> c
//.. -> ..
#define SIZE 5
bool check[SIZE]; //bool array to check if traversed to that node yet or not

void dfs(int node, int depth){
    if (check[node] == true)
        return;
    check[node] = true;
    cout << "node " << node << " is at depth lv " << depth <<endl ;
    for(int i = 0; i < adj[node].size(); i++)
        dfs(adj[node][i], depth+1);
}

void addEdge(vector<int> adj[], int u, int v){
    //undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);//remove this line for directed graph

    
}

void print_graph(vector<int> adj[]){
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        for (auto child:adj[i])
            cout << child << " ";
        cout << endl;
    }
    
}
int main(){
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 3, 5);

    dfs(1, 0);
    cout << "Adjacency list"<< endl;
    print_graph(adj);
    return 0;
}