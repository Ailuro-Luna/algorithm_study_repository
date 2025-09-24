// https://neetcode.io/problems/trapping-rain-water
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        
        int l =0;
        int r = 0;
        int total_water = 0;
        int curr_water = 0;
        int l_index = 0;

        vector<int> local_max;
        vector<int> local_min;

        for(auto i=1;i<heights.size()-1;++i) {
            if(heights[i]<heights[i-1] && heights[i]<heights[i+1]) {local_min.push_back(i);}
            if(heights[i]>heights[i-1] && heights[i]>heights[i+1]) {local_max.push_back(i);}
        }

        for(auto i=0;i<heights.size();++i) {
            if(l<=heights[i]) {
                // 
                total_water += curr_water;
                l=heights[i];
                l_index = i;
                curr_water = 0;
            }
            else {
                curr_water += (l-heights[i]);
            }
        }

        if(curr_water == 0) {return total_water;}

        curr_water = 0;

        for(int i= heights.size()-1;i>=l_index;--i) {
            if(r<=heights[i]) {
                total_water += curr_water;
                r=heights[i];
                curr_water = 0;
            }
            else {
                curr_water += (r-heights[i]);
            }
        }
        
        return total_water;
    }
};
