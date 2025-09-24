// https://neetcode.io/problems/maximum-subarray?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=-100000;
        int max_sum=sum;
        for(const auto& num:nums) {
            if(num>=0) {
                if(sum<0){
                    sum=num;
                } else {
                    sum+=num;
                }
            } else {
                if(sum+num>=0) {
                    sum+=num;
                } else {
                    sum = num;
                }
            }
            // cout<<sum<<endl;
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};