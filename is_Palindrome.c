#include <stdio.h>
#include <stdbool.h> 
#include <math.h>
#include <limits.h>

bool is_Palindrome(int x){
    if (x < 0)
    {
        return false;
    }
    int nDigits = floor(log10(abs(x))) + 1;
    char x_str[nDigits];

    const char base_string[] = "base_string";
    char out_string [MAX_BUFFER_SIZE];
    int number = 123;
    sprintf(out_string, "%s%d", base_string, number);
    printf("out_string = %s\n", out_string);

    printf("%s",x_str);

}



int main(){
    is_Palindrome(1234);
    return 0;
}
