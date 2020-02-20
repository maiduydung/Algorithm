// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};



struct ListNode *reverse(struct ListNode *head, int* len){
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
        *len = *len + 1;
       
    }
    
    head = prev;

    return head;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len;
    head = reverse(head, &len);
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    
    int i = 1;
    printf("length %d", len);

    if(len == 1)
    {
        struct ListNode *empty = NULL;
        head = empty;
    }
    
    while (curr != NULL)
    {        
        if (i == n)
        {
            prev ->next = curr ->next;
            curr ->next = NULL;
        }

        prev = curr;
        curr = curr ->next;
        i++;
    }
    head = reverse(head, &len);


    return head;
}

int main(){
    return 0;
}