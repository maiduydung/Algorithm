//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode *root, int result = 0){
        if(!root) return 0;
        result = result*2 + root->val;//every time we go 1 lv lower, the result got multiplied by 2
        //001 = 1
        //010 = 1*2 = 2
        //100 = 1*2*2 = 4

        if((root->left == NULL) && (root->right == NULL))
            return result;
        else{
            return dfs(root->left, result) + dfs(root->right, result);
        }
    }
};