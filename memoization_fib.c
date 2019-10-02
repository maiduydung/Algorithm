#include <stdio.h>
#include < 
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
    int [] checked_arr = malloc()

    return 0;
}