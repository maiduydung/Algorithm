// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Given a Binary Search Tree and a target number 
// return true if there exist two elements in the BST 
// such that their sum is equal to the given target.

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
// Target = 9

// Output: True

//we can solve this with bfs too

#include <bits/stdc++.h> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//node_A->val + node_B->val = k
//each time we traverse to a node, check if k - node->val is in the hashset
//if true, we found 2 node needed
class Solution {
public:
    unordered_set <int> checkSet; 
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return 0;
        if(checkSet.count(k - root->val) == 1)
            return 1;
        checkSet.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
        //we need to get the value to exit the stack, so that the RETURN at the end is needed, 
        //sth like findTarget(root->left,k) wont work
        //OR operator, because other stack may return a 0 (leaf node)
        //0 || 1 = 1

    }
};