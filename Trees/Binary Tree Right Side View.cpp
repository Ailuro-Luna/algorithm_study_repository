//https://neetcode.io/problems/binary-tree-right-side-view?list=neetcode150
#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root ==nullptr) {
            return res;
        }
        int max_depth=0;
        dfs(root,1,max_depth,res);
        return res;
    }

    void dfs(TreeNode* node, int current_depth, int& max_depth, vector<int>& res) {
        if(current_depth>max_depth) {
            res.push_back(node->val);
            max_depth = current_depth;
        }
        if(node->right!=nullptr) {
            dfs(node->right, current_depth+1, max_depth, res);
        }
        if(node->left!=nullptr) {
            dfs(node->left, current_depth+1, max_depth, res);
        }
    }
};
