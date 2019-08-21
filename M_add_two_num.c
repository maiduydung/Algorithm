/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

int reverse_num(int x){
    int reversed = 0;
    while (x > 0)
    {
        reversed = reversed*10 + x % 10;
        x = x / 10;
    }

    return reversed;
}

int get_reverse(struct ListNode *l){
    struct ListNode  *l_temp = l;
    int reversed = 0;
    int val_to_reversed = 0;
    while (l_temp != NULL)
    {
        val_to_reversed = l_temp ->val + val_to_reversed*10;
        //printf("%d\n",val_to_reversed);
        l_temp = l_temp ->next;
        
    }
    reversed = reverse_num(val_to_reversed);
    return reversed;
}

void append (struct ListNode **l, int new_val){
    struct ListNode *new_node = malloc(sizeof new_node);
    struct ListNode *last = l;

    new_node -> val = new_val;
    new_node -> next = NULL;

    if (*l == NULL)
    {
        *l = new_node;
        return ;
    }

    while (last -> next != NULL)
    {
        last = last ->next;
    }
    last ->next = new_node;
    return ;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int a = get_reverse(l1);
    int b = get_reverse(l2);

    int c_reversed = reverse_num(a+b);
    printf("%d\n",c_reversed);

    struct ListNode *l3;

    int temp_val = 0;



    while (c_reversed > 0)
    {
        temp_val = c_reversed % 10;
        c_reversed = c_reversed / 10;
        //adding into node
        printf("%d\n",temp_val);
        append(&l3,temp_val);
    }
    

    return l3;
}