// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};




struct ListNode* removeNthFromEnd(struct ListNode* head, int n){   
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    for(int i = 0; i < n; i++){
        //printf("%d \n", fast ->val);
        fast = fast ->next;
    }
    if (fast == NULL){
        printf("head %d", head->val);
        return head->next;
    }
        
    
        

    while (fast->next != NULL) 
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow ->next = slow -> next -> next;
    return head;
}







int main(){
    return 0;
}