//https://neetcode.io/problems/house-robber-ii?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==0) {
            return 0;
        }
        if(len==1) {
            return nums[0];
        }
        if(len==2) {
            return max(nums[0],nums[1]);
        }
        if(len==3) {
            return max(max(nums[0],nums[1]),nums[2]);
        }
        vector<int> values_not_choose_1(nums.size());
        vector<int> values_choose_1(nums.size());
        values_not_choose_1[0]=0;
        values_not_choose_1[1]=nums[1];
        values_choose_1[0]=nums[0];
        values_choose_1[1]=nums[0];
        for(int i=2;i<len;++i) {
            values_not_choose_1[i]=max(values_not_choose_1[i-2]+nums[i],values_not_choose_1[i-1]);
            values_choose_1[i]=max(values_choose_1[i-2]+nums[i],values_choose_1[i-1]);
        }
        values_choose_1[len-1] = values_choose_1[len-2];
        return max(values_not_choose_1[len-1], values_choose_1[len-1]);

    }
};
