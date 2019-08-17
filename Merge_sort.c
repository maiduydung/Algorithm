#include <stdio.h>
#include <stdlib.h>

void Merge(int *arr, int start, int mid, int end){
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    //traversing both arrays comparing element and adding to temp array
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    //adding the remaining element to array
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    // printf("%d - %d\n", start, end);
    // for (int i = 0; i < sizeof temp / sizeof temp[0]; i++)
    // {
    //     printf("%d\n",temp[i]);
    //     //arr[i] = temp[i];
    // }
    // printf("=========================\n");
    for (i = start; i <= end ; i++)
    {
        arr[i] = temp[i - start];
    }
    

    
}

void MergeSort(int *arr, int start, int end){
    printf("%d - %d\n", start, end);
    if (start < end)
    {
        int mid = (end + start) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        
        //Merge(arr, start, mid, end);
    }
    
}


int main(){
    int a[] = {90,4,5,82,1,2,0,43};
    int sizeof_arr = sizeof a / sizeof a[0];

    MergeSort(a, 0, sizeof_arr-1);

    // for (int i = 0; i < sizeof_arr ; i++)
    // {
    //     printf("%d\n", a[i]);
    // }

    return 0;
}