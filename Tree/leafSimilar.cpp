// https://leetcode.com/problems/leaf-similar-trees/
// Two binary trees are considered leaf-similar 
// if their leaf value sequence is the same.
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        //since comparing value of each node directly doesnt work (actually i think this can totally work, just not sure why the code doesn't)
        //we need a workaround, so, vector
        pre_order(root1, v1);
        pre_order(root2, v2);
        return v1 == v2; //namespace std provides the == operator, really useful in this case
    }

    void pre_order(TreeNode *root, vector<int> &vect)//dont forget to pass by reference &, we need to store the value to vector
    {
        if (!root)
            return;
        if((root ->left == NULL) && (root->right == NULL))
            vect.push_back(root->val);
        pre_order(root->left, vect);
        pre_order(root->right, vect);
        
    }
};
    //sth like this wouldnt work, somehow use with
    //return pre_order(root1) == pre_order(root2);
    //always return a true
    // int pre_order(TreeNode *root){
    //     if(root)
    //     {
    //         if((root ->left == NULL) && (root->right == NULL))
    //             return root->val;
    //         pre_order(root->left);
    //         pre_order(root->right);
    //     }
    //     return 0;
    // }