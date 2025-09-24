//https://neetcode.io/problems/serialize-and-deserialize-binary-tree
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        treeToStr(root,str);
        return str;
    }

    void treeToStr(TreeNode* node, string& str) {
        if(node == NULL) {
            str+="NULL\n";
            return;
        }
        str += to_string(node->val);
        str += "\n";
        treeToStr(node->left, str);
        treeToStr(node->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<data<<endl;
        string token = "";
        stack<TreeNode*> node_stack;
        TreeNode* root=NULL;
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*, int> stage; // number of children. 0: left; 1: right; 2: back-track
        // int stage=0; 
        for(int i=0;i<data.size();i++) {
            if(data[i]!='\n') {
                token += data[i];
                continue;
            }


            if(token=="NULL") {
                if(!node_stack.empty()) {
                    ++stage[node_stack.top()];
                    while(!node_stack.empty()&&stage[node_stack.top()]==2) {
                        node_stack.pop();
                    }
                }
                
                token = "";
                continue;
            }


            // no more children, back-track
            while(!node_stack.empty() && stage[node_stack.top()]==2) {
                node_stack.pop();
            }


            TreeNode* node = new TreeNode(stoi(token));
            if(node_stack.empty()) {
                node_stack.push(node);
                if(root==NULL) {
                    root = node;
                }
            } else {
                if(stage[node_stack.top()]==0) {
                    node_stack.top()->left=node;
                } else {
                    node_stack.top()->right=node;
                }
                parent[node] = node_stack.top();
                ++stage[node_stack.top()];
                node_stack.push(node);
            }

            token = "";
        }

        return root;
    }


};
