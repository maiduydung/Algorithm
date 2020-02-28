#include <stdio.h>
int a[10], n, stop; 

void init() 
{
    stop=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        a[i]=0;
}

void print() 
{
    for(int i=0;i<n;i++)
        printf("%d", a[i]);
    printf("\n");
}

void generate() 
{
    int i=n-1;
    while(i>=0 && a[i]==1)
        i--;

    if(i<0) stop=1; 
    else
    {
        a[i]=1;  
        for(int j=i+1;j<n;j++)  
            a[j]=0;
    }
}

void enumerate() 
{
    init(); 
    while(!stop)
    {
        print(); 
        generate(); 
    }
}

int main()
{
    enumerate(); 
}