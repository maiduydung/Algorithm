#include<stdio.h>

unsigned int gdc(unsigned int a, unsigned int b){
    int swap;
    int r;
    if (a < b)
    {
        swap = a;
        a = b;
        b = swap;
    }
    while (r != 0)
    {
        r = a % b;
        if (r == 0)
        {
            break;
        }
        
        a = b;
        b = r;
    }
    return b;
}

int main(){
    printf("%d\n",gdc(48,36));
    return 1;
}