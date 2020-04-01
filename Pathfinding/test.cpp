#include <iostream>
#include <vector>
using namespace std;

void add_edge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//array of vectors
void print_graph(vector<int> adj[], int adj_size){
    for (auto v = 0; v < adj_size; v++){
        cout << v;
        for(auto x: adj[v])
            cout << " -> " << x;
        cout << "\n" ;
    }
}

int main(){
    vector<int> v1[5]; 
    add_edge(v1,0,1);
    add_edge(v1,0,4);
    add_edge(v1,1,4);
    add_edge(v1,2,1);
    add_edge(v1,3,1);
    add_edge(v1,4,2);

    print_graph(v1,5);
    return 0;
}