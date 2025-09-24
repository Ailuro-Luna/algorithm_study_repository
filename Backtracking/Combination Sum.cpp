//https://neetcode.io/problems/combination-target-sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        int current_val = 0;
        int idx=0;
        back_tracking(nums, res, target, current, current_val, idx);
        return res;
    }

    void back_tracking(vector<int>& nums, vector<vector<int>>& res, int target, vector<int>& current, int current_val, int idx) {
        if(current_val == target) {
            res.push_back(current);
            return;
        }
        
        if(idx>=nums.size() || current_val>target) {
            return;
        }

        for(int i=idx;i<nums.size();++i) {
            current.push_back(nums[i]);
            current_val+=nums[i];
            back_tracking(nums, res, target, current, current_val, i);
            current.pop_back();
            current_val-=nums[i];
        }
    }
};
