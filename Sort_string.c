#include <stdio.h>
#include <string.h>

char *merge(char a[], char b[]){
    
    //, int a_n, int b_n
    static char c[2];//only needs 2 elements //static to return array

    //check if arr a or b not empty
    //strings end with NULL
    while(a[0] != 0 && b[0] != 0){
        if (a[0] > b[0]){
            c[0] = b[0];
            a[0] = 0;
        }
        else{
            c[0] = a[0];
            b[0] = 0;
        }
    } //either a or b is empty now

    while(a[0] != 0){
        c[1] = a[0];
        a[0] = 0;
    }
    while(b[0] != 0){
        c[1] = b[0];
        b[0] = 0;
    }
    return c;
}

char *mergesort(char a[], int n){
    if(n == 1){
        return a;
    }
    //char arr_one[] =  a[0]...a[n/2];
    //printf("%d\n\n\n", n);
    
    ////copying to arr_one
    char arr_one[n/2];
    for(int i = 0; i < n/2; i++){
        arr_one[i] = a[i];    
        //printf("%c\n", arr_one[i]);
    }
//printf("\n\n\n\n");

    ////copying to arr_two
    char arr_two[n/2];
    for(int i = (n/2) ; i <= n; i++){
        arr_two[i] = a[i];
        //printf("%c\n", arr_two[i]);
    }



    return merge(arr_one, arr_two);
}


int main(){
    char my_name[] ="maiduydung";
    int elements = sizeof(my_name) / sizeof(my_name[0]);
    mergesort(my_name, elements);

    printf("%s\n", my_name);
}
