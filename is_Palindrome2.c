#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool is_Palindrome2(int x){
    int x_copy = x;
    int result = 0;
    if (x < 0)
    {
        return false;
    }
    
    while (x_copy > 0)
    {
        //printf("%d\n", result);
        if (result > INT_MAX / 10 || result < INT_MIN / 10)
        {
            return false;
        }
        
        result = result*10 + (x_copy % 10);
        x_copy = x_copy / 10;
    }
    //printf("%d - %d\n", x, result);
    return result == x;
    
}

int main(){
    printf("%d\n", is_Palindrome2(72327));
    return 0;
}