#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int reverse (int x)
{
    int result = 0;
    int right_num;

    while (x != 0)
    {
        right_num = x % 10;
        x = x / 10;
        result = result*10 + right_num;
    }
    return result;

}

int main(){
    
    printf("%d\n",reverse(1234));
    return 0;  
}
