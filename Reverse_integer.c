#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int reverse (int x)
{
    int32_t my_32bit_int;
    if (x != 0)
    {
        int nDigits = floor(log10(abs(x))) + 1;
        char x_str[nDigits];
        sprintf(x_str,"%d",x);
       
        printf("%s",x_str);

        for (int i = strlen(x_str); i >= 0 ; i--)
        {
            printf("%c",x_str[i]);
        }

        //return nDigits;
    }
    return 0;
}

int main(){
    
    reverse(1234);
    //printf("%d\n",reverse(1234));

    return 0;  
}
