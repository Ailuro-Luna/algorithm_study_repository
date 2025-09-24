// https://neetcode.io/problems/three-integer-sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()<3) {return {};}

        vector<vector<int>> ans;

        size_t i,j,k;
        sort(nums.begin(), nums.end());
        for(j = 1;j<nums.size()-1;++j) {
            i = 0;
            k=nums.size()-1;
            int target = -nums[j];

            int sum = nums[i]+nums[k];
            
            while(i<j && j<k) {
                if(sum==target) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    ++i;
                    --k;
                } else if(sum<target) {
                    ++i;
                } else {
                    --k;
                }
                sum = nums[i]+nums[k];
            }
        }
        // 去重
        set<vector<int>> set1;
        for(auto& tri:ans) {
            set1.insert(tri);
        }
        ans.clear();
        for(auto& tri:set1) {
            ans.push_back(tri);
        }
        return ans;
    }
};
