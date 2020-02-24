// https://leetcode.com/problems/swap-nodes-in-pairs/

#include<stdio.h>
#include <stdbool.h> 


struct ListNode{
    int val;
    struct ListNode *next;
};

int swap_node(struct ListNode *l1){
    struct ListNode *temp1, *temp2;
    while (l1->next && l1->next->next)
    {
        temp1 = l1 ->next;
        temp2 = l1 ->next ->next;

        l1 ->next = temp2;
        temp1 ->next = temp2 ->next;
        temp2 ->next = temp1;

        return 1;
    }
    return 0;
}
struct ListNode* swapPairs(struct ListNode* head){
    if (!head)
        return NULL;
    
    
    struct ListNode *new_head = (struct ListNode*)malloc(sizeof (struct ListNode));
    new_head ->next = head;
    struct ListNode *p = new_head;

    while(swap_node(p)){
        p = p ->next ->next;
    }
    return new_head ->next;
}
