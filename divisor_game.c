#include<stdio.h>
#include<stdbool.h>

bool divisorGame(int N){
    if (N <= 1)
        return false;
    else
        return true;
    
    printf("n %d\n", N);
    for (int i = N - 1; i >0; i--)
    {   
        if (N % i == 0)
        {
            //printf("i %d\n", i);
            N = N - i;
            divisorGame(N);
        }
        
    }
    
}

int main(){

    divisorGame(30);
    return 0;
}