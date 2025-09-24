// https://neetcode.io/problems/top-k-elements-in-list
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> num_map;
        vector<int> res;
        for(auto num:nums) {
            ++num_map[num];
        }

        vector<pair<int,int>> pairs;

        for(auto num_pair:num_map) {
            pairs.push_back(num_pair);
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int,int> &a, const pair<int, int> &b) {
            return a.second>b.second;
        });

        for(int i=0;i<k;i++) {
            res.push_back(pairs[i].first);
        }

        return res;
    }
};
