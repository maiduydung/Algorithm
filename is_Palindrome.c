#include <stdio.h>
#include <stdbool.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>

bool is_Palindrome(int x){
    if (x < 0)
    {
        return false;
    }
    int nDigits = floor(log10(abs(x))) + 1;
    char x_str[nDigits];

    sprintf(x_str, "%d", x);
    //printf("%s\n",x_str);

    for (int i = 0; i <= strlen(x_str); i++)
    {
        //printf("%c",x_str[strlen(x_str) - i]);

        // if (x_str[i] != x_str[strlen(x_str) - i])
        // {
        //     return false;
        // }
        
    }
    return true;
}



int main(){
    is_Palindrome(12321);
    //printf("%d",is_Palindrome(12321));
    return 0;
}
