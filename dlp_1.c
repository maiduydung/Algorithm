// This problem was recently asked by Google.

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include <stdio.h>
#define SIZE 10

//basic hash
void hash(int arr[], int hash_arr[]){
    for (int i = 0; i < SIZE; i++)
    {
        hash_arr[i] = arr[i]%SIZE;
    }
    
}

int get_hashed_val(int num){
    return num % SIZE;
}

int sum(int arr[], int lookup_val){

    int hashed_arr[SIZE]; 
    hash(arr, hashed_arr);
    // for (int i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", hashed_arr[i]);
    // }
    
printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        int diff = lookup_val - arr[i];        
        for (int j = i+1; j < SIZE; j++)
        {
            if (arr[j] == diff)
                printf("%d %d\n",arr[i], diff);            
        }
    }
}


int main(){
    int input_arr[SIZE] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sum(input_arr, 11);
}