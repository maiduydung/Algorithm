// https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} LL;



double reverse_cal(struct ListNode *l1){
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    struct ListNode *current = l1; 
    double result = 0;
    int i = 0;
    while (current != NULL)
    {
        next = current ->next;
        current ->next = prev;

        //2 -> 4 -> 3
        //2*pow(10,0)
        //4*pow(10,1)
        //3*pow(10,2)
        
        result = result + current->val*pow(10, i);

        i++;
        prev = current;
        current = next;
        
    }
    l1 = prev;
    return result;
} 
struct ListNode* insert_ll(struct ListNode* l1, int num){
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode)); 
    struct ListNode *last = l1;
    new_node->val  = num; 
    new_node->next = NULL; 
  

    if (l1 == NULL) 
    { 
       l1 = new_node; 
       return; 
    }   
       
    while (last->next != NULL) 
        last = last->next; 
   
    last->next = new_node; 
    return l1;
    
}

struct ListNode *slice_num(struct ListNode* l1, int num){
    while (num != 0)
    {
        printf("%d %d\n",num ,num % 10);
        l1 = insert_ll(l1, num % 10);
        num = num / 10;
    }

    return l1;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    double l1_val = reverse_cal(l1);
    double l2_val = reverse_cal(l2);
    double sum = l1_val + l2_val;
    

    struct ListNode *result = NULL;

    result = slice_num(result, sum);
    
    return result;
}
int main(){

}