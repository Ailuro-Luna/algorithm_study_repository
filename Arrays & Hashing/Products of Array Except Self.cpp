// https://neetcode.io/problems/products-of-array-discluding-self
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        long long product = 1;
        size_t zero_count = 0;
        int zero_index = 0;
        int index = 0;
        for (auto& num:nums) {
            if(num==0) {
                ++zero_count;
                zero_index = index;
            }
            else {
                product *= num;
            }
            ++index;
        }

        if(zero_count >=2) {
            vector<int> ans(nums.size());
            return ans;
        }

        if(zero_count ==1) {
            vector<int> ans(nums.size());
            ans[zero_index] = product;
            return ans;
        }

        vector<int> ans;
        for (auto& num:nums) {
            if(num!=0) 
            ans.push_back(product/num);
        }
        return ans;
    }
};
