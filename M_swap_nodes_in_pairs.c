// https://leetcode.com/problems/swap-nodes-in-pairs/
//Given 1->2->3->4, you should return the list as 2->1->4->3.
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
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