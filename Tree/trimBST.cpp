// https://leetcode.com/problems/trim-a-binary-search-tree/
// Trim the tree so that all its elements lies in [L, R] (R >= L). 
// You might need to change the root of the tree, 
// so that result should return the new root of the trimmed binary search tree.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL; //end
        if(root->val < L) //if val is smaller than L, then lookup at the right sub tree(we're at binary tree here)
            return trimBST(root->right, L, R);//we cant assign root here yet, simply because we  don't know the value
        if(root->val > R)
            return trimBST(root->left, L, R); //same as above
        root ->left = trimBST(root->left, L, R);
        root ->right = trimBST(root->right, L, R);
        return root;
    }
};