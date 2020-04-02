//https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int lookup_val) {
        if(root){
            if (root->val == lookup_val)
                return root;
            if(root->val > lookup_val)
                //using return to get the value of subnode
                return searchBST(root->left, lookup_val);
            if(root->val < lookup_val)
                return searchBST(root->right, lookup_val);
        }
        return NULL;
    }
};