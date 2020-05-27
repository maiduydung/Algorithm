#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b){
    return a < b? a:b;
}

int max(int a, int b){
    return a > b? a:b;
}

void interleave(char *p_a, char *p_b, char *p_des){
    
    int size = strlen(p_a) + strlen(p_b);
    int minlen = min(strlen(p_a), strlen(p_b));
    int maxlen = max(strlen(p_a), strlen(p_b));

    for (int id = 0; id < size;)
    {
        int i;
        for (i = 0; i < minlen; i++)
        {
            p_des[id] = p_a[i];
            p_des[id+1] = p_b[i];
            id = id + 2;
        }

        for (; i < maxlen; i++)
        {
            if (strlen(p_a) > strlen(p_b))
            {
                p_des[id] = p_a[i];

            }
            else 
            {
                p_des[id] = p_b[i];

            }
            id++;
        }

    }
    
    

    
    
}

int main(){
    char *a = "Toyo";
    char *b = "University";
    char *des;
    int des_size = strlen(a) + strlen(b);
    des = (char*)malloc(des_size);

    
    interleave(a,b,des);
    printf("%s\n", des);


    return 0;
}