#include <stdio.h>
#include <malloc.h>
int fib(int n, int checked[]){
    if (n <= 1) return n;
    if (checked[n]) return n;
    else{
        checked[n] = fib(n-1, checked) + fib(n-2, checked);
        return checked[n];
    }
}

int main(){
    int n = 100;
    

    return 0;
}