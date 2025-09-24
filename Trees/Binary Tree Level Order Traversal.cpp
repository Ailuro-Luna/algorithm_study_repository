//https://neetcode.io/problems/level-order-traversal-of-binary-tree
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
 

struct Node_level {
    TreeNode* node;
    int level;
    Node_level(TreeNode* node, int level) : level(level), node(node) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }
        queue<Node_level> bfs_queue;
        Node_level root_level(root,0);
        bfs_queue.push(root_level);
        while(!bfs_queue.empty()) {
            TreeNode* current_node=bfs_queue.front().node;
            int current_level=bfs_queue.front().level;
            Node_level current(current_node, current_level);
            bfs_queue.pop();
            if(current_level>=res.size()) {
                vector<int> new_level;
                res.push_back(new_level);
            }
            res[current_level].push_back(current_node->val);
            if(current_node->left!=nullptr) {
                bfs_queue.push(Node_level(current_node->left, current_level+1));
            }
            if(current_node->right!=nullptr) {
                bfs_queue.push(Node_level(current_node->right, current_level+1));
            }
        }

        return res;
    }
};
