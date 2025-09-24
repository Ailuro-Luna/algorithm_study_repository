// https://neetcode.io/problems/max-water-container
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int max_contain = 0;
        vector<pair<int,int>> left_bars,right_bars;

        int max_height = 0;
        for(auto i =0;i<heights.size();++i) {
            if(heights[i]<max_height) {continue;}
            left_bars.push_back({heights[i],i});
            max_height = heights[i];
        }

        max_height = 0;
        for(int i =heights.size()-1;i>=0;--i) {
            if(heights[i]<max_height) {continue;}
            right_bars.push_back({heights[i],i});
            max_height = heights[i];
        }

        for(const auto &[l_height,l_index]:left_bars) {
            for(const auto &[r_height,r_index]:right_bars) {
                if (l_index>=r_index) {continue;}
                max_contain = max(max_contain, min(l_height,r_height)*(r_index-l_index));
            }
        }
        return max_contain;

    }
};
