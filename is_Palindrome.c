#include <stdio.h>
#include <stdbool.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool is_Palindrome(int x){
    if (x < 0)
    {
        return false;
    }
    if (x > INT_MAX/10 || x < INT_MIN/10) return false; // int overflow check
    int nDigits = floor(log10(abs(x))) + 1;
    char x_str[nDigits];

    sprintf(x_str, "%d", x);
    //printf("%s\n",x_str);

    for (int i = 0; i < strlen(x_str); i++)
    {
        //printf("%c / %d - %c / %ld\n", x_str[i], i, x_str[strlen(x_str) - i - 1], strlen(x_str) - i - 1);

        if (x_str[i] != x_str[strlen(x_str) - i - 1])
        {
            return false;
        }
        
    }
    return true;
}



int main(){
    //is_Palindrome(12321);
    printf("%d\n",is_Palindrome(1221));
    return 0;
}
