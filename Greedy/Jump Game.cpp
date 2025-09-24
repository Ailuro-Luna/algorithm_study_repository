// https://neetcode.io/problems/jump-game?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest_pos = 0;
        int current_pos = 0;
        while(current_pos<=furthest_pos) {
            furthest_pos = max(furthest_pos, current_pos+nums[current_pos]);
            if(furthest_pos>=nums.size()-1) {
                return true;
            }
            ++current_pos;
        }
        return false;
    }
};
