#include <stdio.h>
#define N 3
int arr[N];
int flag = 0;
void init(){
    for (int i = 0; i < N; i++)
        arr[i] = i+1;
    
}

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void print(){
    for (int i = 0; i < N; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void permu(){
    int i = N -1;
    int k =
    while (i > 0 && arr[i] > arr[i+1])
        i--;
    

}
int main(){

    init();
    permu();


}