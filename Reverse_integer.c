#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int reverse (int x)
{
    int32_t my_32bit_int;
    if (x != 0)
    {
        int nDigits = floor(log10(abs(x))) + 1;
        char x_str[nDigits];

        return nDigits;
    }
    return 0;
}

int main(){
    
    printf("%d\n",reverse(1234));

    return 0;  
}
