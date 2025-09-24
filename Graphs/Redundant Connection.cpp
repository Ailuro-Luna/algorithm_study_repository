// https://neetcode.io/problems/redundant-connection?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {

/*
Input: edges = [[1,2],[1,3],[3,4],[2,4]]
Output: [2,4]

DSU->check before connect

connect and check one by one
if not need, stack it


*/


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>redundant;
        vector<int>parent(edges.size()+1);
        for(int i=1;i<edges.size()+1;++i) {
            parent[i]=i;
        }
        for(auto& edge:edges) {
            if(find_DSU(edge[0], parent)==find_DSU(edge[1], parent)) {
                return edge;
            }
            union_DSU(edge[0], edge[1], parent);
        }

        return redundant;
    }

private:
    void union_DSU(int a, int b, vector<int>& parent) {
        parent[parent[a]]=parent[b];
    }

    int find_DSU(int a, vector<int>& parent) {
        if(parent[a]==a) {
            return a;
        }
        parent[a] = find_DSU(parent[a], parent);
        return parent[a];
    }

};
