#include <stdio.h>

int hash(char c){
    switch (c)
    {
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;
        default: return 0;
    }
}

int romanToInt(char * s){
  
    int re = 0;
    for (int i = 0; s[i] !='\0' ; i++)
    {
        if ( hash(s[i]) < hash(s[i+1]) )
        {
            re = re + hash(s[i+1]) - hash(s[i]);
            i++;
        }
        else
        {
            re = re + hash(s[i]);
        }
        
        
    }
    return re;
}

int main(){
    printf("%d\n",romanToInt("IV"));
    return 0;
}