//https://leetcode.com/problems/merge-k-sorted-lists/solution/
// Example 
//     input [[1,4,5],[1,3,4],[2,6]]
//     output [1,1,2,3,4,4,5,6]
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void traverse(struct ListNode *ll){
    while (ll)
    {
        printf("%d ", ll->val);
        ll = ll ->next;
    }
    
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    for (int i = 0; i < listsSize; i++)
    {
        traverse(lists[i]);
    }
    
}

