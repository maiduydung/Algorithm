//https://leetcode.com/problems/univalued-binary-tree/

// A binary tree is univalued if every node in the tree has the same value.
// Return true if and only if the given tree is univalued.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;//leaf node, nothing left to compare, so we take it as it is or can compare to itself for extra work if you'd like :) 
        if(root->right)
            if(root->val != root->right->val)
                return false;
        // both here and below we need to return false
        // or else the whole function will always return true, we dont want that

        //sth like this wouldn't work
        // if(root->val == root->right->val)
            //     return true;
        // if(root->val == root->left->val)
            //     return true;

        if(root->left)
            if(root->val != root->left->val)
                return false;//

        return isUnivalTree(root->left) && isUnivalTree(root->right); 
        // 0 and 1 = 0
        // 1 and 1 = 1 
    }
};
//its amazing such a simple problem can expand so much