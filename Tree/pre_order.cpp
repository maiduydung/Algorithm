//https://leetcode.com/problems/n-ary-tree-preorder-traversal/
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
private:
    void traverse(Node* root, vector<int> &result){
        if(!root) return;
        for(Node* child:root->children){
            traverse(child, result);
        }
        result.push_back(root->val);
    }
};