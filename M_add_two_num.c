/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int a = get_reverse(l1);
    int b = get_reverse(l2);
    printf("%d",a+b);
    return l1;
}

