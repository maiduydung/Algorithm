#include <stdio.h>
#include <string.h>

char *int_to_roman(int n)
{
    char *re;
    //returning string
    int last = n % 5;
    n = n - last;

    if (last == 4)
        strcpy(re, "IV");        
    if (last == 9)
        strcpy(re, "IX");        
    
    
    
    return re;
}

int main()
{
    int_to_roman(102);

    return 0;
}