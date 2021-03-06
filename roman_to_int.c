#include <stdio.h>
#include <string.h>

int romanToInt(char * s){
    int re = 0;
    for (int i = 0; s[i]; i++)
    {
        if (i > 0) goto special;
    
        
        special:
            if (s[i-1]=='I' && s[i]=='V' || s[i-1] == 'I' && s[i] == 'X')
                re = re - 2;
            if (s[i-1]=='X' && s[i]=='L' || s[i-1]=='X' && s[i]=='C')
                re = re - 20;
            if (s[i-1]=='C' && s[i]=='D' || s[i-1]=='X' && s[i]=='M')
                re = re - 200;
        
        // end of special cases
        
        if (s[i]=='I') 
            re = re + 1;
        if (s[i]=='V')
            re = re + 5;
        if (s[i]=='X')
            re = re + 10;
        if (s[i]=='L')
            re = re + 50;
        if (s[i]=='C')
            re = re + 100;
        if (s[i]=='D')
            re = re + 500;
        if (s[i]=='M')
            re = re + 1000;

    }
    return re;    
}

int main(){
    printf("%d\n",romanToInt("MIX"));
    return 0;
}
