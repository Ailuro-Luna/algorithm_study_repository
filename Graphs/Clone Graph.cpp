// https://neetcode.io/problems/clone-graph?list=neetcode150
#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> oldToNewMap;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        if (oldToNewMap.count(node)) {
            return oldToNewMap[node];
        }
        Node* new_node = new Node(node->val);
        oldToNewMap[node] = new_node;
        for(auto & neighbor:node->neighbors) {
            // if(neighbor->val<node->val) {
            //     continue;
            // }
            Node* new_neighbor = cloneGraph(neighbor);
            // new_neighbor->neighbors.push_back(new_node);
            new_node->neighbors.push_back(new_neighbor);
        }
        return new_node;
    }


};
