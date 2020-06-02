#include<iostream>
using namespace std;
void fib(int n){
    int vals[n];
    vals[0] = 1;
    vals[1] = 1;
    for (int i = 2; i < n; i++)
    {
        vals[i] = vals[i-2] + vals[i-1];
    }
    
    //////
    for (int i = 0; i < n; i++)
    {
        cout << vals[i] << " ";
    }
    
}

int main(){
    fib(10);
}