#include <stdio.h>

void merge(){

}

char *mergesort(char a[], int n){
    if(n == 1){
        return a;
    }
    //char arr_one[] =  a[0]...a[n/2];
    printf("%d\n\n\n", n);
    char arr_one[n/2];
    for(int i = 0; i <= n/2; i++){
        arr_one[i] = a[i];    
        printf("%c\n", arr_one[i]);
    }
printf("\n\n\n\n");
    char arr_two[n/2];
    for(int i = (n/2) + 1; i <= n; i++){
        arr_two[i] = a[i];
        printf("%c\n", arr_two[i]);
    }
}


int main(){
    char my_name[] ="maingochuychan";
    int elements = sizeof(my_name) / sizeof(my_name[0]);
    mergesort(my_name, elements);
}
