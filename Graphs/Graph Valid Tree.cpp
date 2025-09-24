// https://neetcode.io/problems/valid-tree?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;++i) {
            father.push_back(i);
        }
        for(auto &edge : edges) {
            int node1=edge[0];
            int node2=edge[1];
            if(find_father(node1)==find_father(node2)) {
                return false;
            }
            merge(node1,node2);
        }
        for(int i=1;i<n;++i) {
            if(find_father(i)!=find_father(i-1)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> father;
    int find_father(int node) {
        if(father[node]==node) {
            return father[node];
        } else {
            father[node] = find_father(father[node]);
            return father[node];
        }
    }

    void merge(int node1, int node2) {
        if(father[node1]==father[node2]) {
            return;
        }
        father[father[node1]]=father[node2];
    }
};
