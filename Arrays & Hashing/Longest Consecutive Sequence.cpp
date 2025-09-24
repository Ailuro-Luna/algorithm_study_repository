// https://neetcode.io/problems/longest-consecutive-sequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size()==0) {return 0;}

        set<int> num_set(nums.begin(),nums.end());
        int index = 0;
        int pre=-1;
        int now_len =1;
        int max_len = -1;
        for(auto& num:num_set) {
            if(index ==0) {
                pre = num;
                ++index;
                continue;
            }

            int diff = num-pre;
            if(diff == 1) {
                ++now_len;
            }
            else {
                max_len = max(now_len,max_len);
                now_len = 1;
            }

            pre = num;
            ++index;
        }

        max_len = max(now_len,max_len);

        return max_len;
    }
};
