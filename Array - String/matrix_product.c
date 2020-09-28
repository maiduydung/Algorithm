#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main( int argc, char *argv[] )  
{
    int size = 0;
    
    if (!argv[1]) 
        size = 64;
    else
        size = atoi(argv[1]);

    //getchar();

    //row * col
    int (*arr_a)[size] = malloc(sizeof(int[size][size]));
    int (*arr_b)[size] = malloc(sizeof(int[size][size]));
    int (*res)[size] = malloc(sizeof(int[size][size]));

    //init
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            arr_a[i][j] = rand()%10;
    }
    //init b
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            arr_b[i][j] = rand()%10;
    }


    double start_time = clock();

    #pragma omp parallel for
    //calculate
    for (int i = 0; i < size; i++) 
    { 
        for (int j = 0; j < size; j++) 
        { 
            res[i][j] = 0; 
            for (int k = 0; k < size; k++) 
                res[i][j] += arr_a[i][k]*arr_b[k][j]; 
        } 
    } 
    
    double elapsed_time = clock() - start_time;
    printf("Elapsed time: %f\n", elapsed_time);



    free(arr_a);
    free(arr_b);
    free(res);
    
    return 0;
}

