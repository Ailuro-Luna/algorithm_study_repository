// https://neetcode.io/problems/subsets
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> empty_set(0);
        // sets.push_back(empty_set);
        // if(nums.size()==0) {
        //     return sets;
        // }


        back_tracking(nums,0,empty_set,sets);
        return sets;
    }

    void back_tracking(vector<int>& nums,int index, vector<int>& path, vector<vector<int>>& res) {
        if(index>nums.size()) {
            return;
        }
        res.push_back(path);
        for(int i=index;i<nums.size();i++) {
            path.push_back(nums[i]);
            back_tracking(nums,i+1,path,res);
            path.pop_back();
        }
    }


};
