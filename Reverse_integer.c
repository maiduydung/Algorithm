#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int reverse (int x)
{
    int32_t result = 0;
    //int result = 0;
    int right_num;

    while (x != 0)
    {
        right_num = x % 10;
        x = x / 10;
        if (result > INT_MAX/10) return 0;
        if (result < INT_MIN/10) return 0;
        result = result*10 + right_num;
    }
    return result;

}


int main(){
    
    printf("%d\n",reverse(1234));
    return 0;  
}
