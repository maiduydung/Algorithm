#include <stdio.h>
#include <string.h>


char hash(char c){
    switch (c)
    {
        case '1': return 'I'; break;
        case '5': return 'V'; break;
        case '10': return 'X'; break;
        case '50': return 'L'; break;
        case '100': return 'C'; break;
        case '500': return 'D'; break;
        case '1000': return 'M'; break;
        default: return 0;
    }
}

int how_degits(int n){
    int re;
    while (n > 0)
    {
        n = n / 10;
        re++;
    }
    return re;
}

// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
char *int_to_roman(int n)
{
    int degits = how_degits(n);



    char s_num[degits];
    char *re;

    sprintf(s_num, "%d", n);
    printf("string num %s\n", s_num);

    for (int i = degits - 1; i >= 0; i--)
    {   
        hash(s_num[i])
    }
    
    

    return re;
}

int main()
{
    int_to_roman(2001);

    return 0;
}