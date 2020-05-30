#include <iostream>
#include <algorithm>
#include<bits/stdc++.h> 


// Given a binary search tree with non-negative values, 
// find the minimum absolute difference between values of any two nodes.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;

class Solution {
public:
    int min_val = INT_MAX;
    int prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return min_val;
        getMinimumDifference(root->left);
        if(prev)
            min_val = min(min_val, min_val - prev);
        prev = root ->val;
        getMinimumDifference(root->right);
        return min_val;
    }
};