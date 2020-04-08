// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Given a binary tree, find its maximum depth.
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = 0;
        int right = 0;
        left = maxDepth(root->left) + 1;
        right = maxDepth(root->right) + 1;
        return left > right ? left : right;
        //equvalant of 
        // return max(left, right);
        //im trying to cut down runtime here
    }

};