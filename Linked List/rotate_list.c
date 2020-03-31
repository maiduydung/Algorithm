// https://leetcode.com/problems/rotate-list/
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_list(struct ListNode* head){
    struct ListNode *temp = head;
    while (temp != NULL){
        printf("%d \n", temp->val);
        temp = temp ->next;
    }
}



struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *temp = head;
    struct ListNode *prev;
    int i = 0;
    while(i != k)
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp ->next;
        }
        temp ->next = head;
        head = temp;
        prev ->next = NULL;
        i++;
    }

    
    
    

    return head;
}

