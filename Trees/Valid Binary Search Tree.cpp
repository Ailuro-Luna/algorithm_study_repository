// https://neetcode.io/problems/valid-binary-search-tree
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

struct NodeState {
    TreeNode* Node;
    bool valid,l_valid,r_valid;
    int l_min,l_max,r_min,r_max;
    NodeState(TreeNode* Node) {
        this.Node = Node;
        valid = l_valid = r_valid = true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // xxxxxxx
        if(root==NULL) {
            return true;
        }
        // auto[valid,min_val,max_val] = checkValid(root);
        bool res=true;
        stack<NodeState> data_stack; //Node, valid, min,max
        data_stack.push(NodeState(root));
        while(!data_stack.empty()) {
            auto current_state = data_stack.top();
            TreeNode* current_Node = current_state.Node;

            if(current_Node->right) {
                data_stack.push(NodeState(current_Node->right));
            }

            if(current_Node->left) {
                data_stack.push(NodeState(current_Node->left));
            }
            


            data_stack.pop();
        }


        return valid;
    }

private:
// valid,min,max
    tuple<bool,int,int> checkValid(TreeNode* Node) {
        bool valid = true;
        bool l_valid,r_valid;
        int l_min,l_max,r_min,r_max;
        if (Node->left) {
            tie(l_valid,l_min,l_max) = checkValid(Node->left);
        } else {
            l_valid=true;
            l_min=Node->val;
            l_max=Node->val;
        }

        if (Node->right) {
            tie(r_valid,r_min,r_max) = checkValid(Node->right);
        } else {
            r_valid=true;
            r_min=Node->val;
            r_max=Node->val;
        }
        if (Node->left && l_max>=Node->val) {
            valid=false;
        }
        if (Node->right && Node->val>=r_min) {
            valid=false;
        }
        return {valid&&l_valid&&r_valid,l_min,r_max};
    }
};
