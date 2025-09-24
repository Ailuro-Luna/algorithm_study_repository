// https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) {
            swap(p,q); //let p<q
        }

        return FindLCA(root,p,q);
    }

    TreeNode* FindLCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(p->val<=node->val && q->val>=node->val) {
            return node;
        } else if (q->val<node->val) {
            return FindLCA(node->left,p,q);
        } else {
            return FindLCA(node->right,p,q);
        }
    }

    bool backTrack(TreeNode* node, TreeNode* targe, vector<TreeNode*>& path) {
        if(node == NULL) {
            return false;
        }
        path.push_back(node);
        if(node == targe) {
            return true;
        }
        if(backTrack(node->left,targe,path)==true) {
            return true;
        }
        if(backTrack(node->right,targe,path)==true) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
};