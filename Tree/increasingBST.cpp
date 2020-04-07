// https://leetcode.com/problems/increasing-order-search-tree/
// Given a binary search tree, rearrange the tree in in-order 
// so that the leftmost node in the tree is now the root of the tree, 
// and every node has no left child and only 1 right child.
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        vector<int> v1;   
        in_order(root, v1);
        
        TreeNode *new_root = new TreeNode(0);
        TreeNode *temp = new_root;
        for (auto i = 0; i < v1.size(); i++)
        {
            temp->right = new TreeNode(v1[i]);
            temp = temp->right;
        }
        return new_root->right;
    }

    void in_order(TreeNode*root, vector<int> &vect){
        if(root){
            in_order(root ->left, vect);
            vect.push_back(root->val);
            in_order(root ->right, vect);
        }
        return;
    }
};