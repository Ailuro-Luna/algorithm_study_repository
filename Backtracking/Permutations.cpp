//https://neetcode.io/problems/permutations?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        vector<int> current;
        function<void()> dfs = [&] {
            if(current.size()==nums.size()) {
                res.push_back(current);
                return;
            }
            for(int i=0;i<nums.size();++i) {
                if(used[i]) {
                    continue;
                }
                current.push_back(nums[i]);
                used[i]=true;
                dfs();
                used[i]=false;
                current.pop_back();
            }
        };
        dfs();
        return res;
    }



    void backtrack(int start_pos, vector<int>& current,vector<vector<int>>& res, vector<int>& nums) {
        if(current.size()==nums.size()) {
            res.push_back(current);
            return;
        }

        for(int i=start_pos;i<nums.size();++i) {
            current.push_back(nums[i]);
            backtrack(start_pos+1, current, res, nums);
            current.pop_back();
        }
    }
};
