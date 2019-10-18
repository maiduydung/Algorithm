#include <stdio.h>
#include <stdlib.h>

int mem_fib(int a, int checked[]){
    if (a <= 0) return 0;
    else if (a == 1) return 1;
    else if (checked[a] > 0) return checked[a];

    checked[a] = mem_fib(a-1,checked) + mem_fib(a-2,checked);
    return checked[a];
}

void all_fib(int n){
    
    int *checked = (int*) malloc((n) * sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        printf("i: %d\n",mem_fib(i,checked));
    }
    free(checked);
    return;
}

int main(){
    all_fib(21);
    return 0;
}