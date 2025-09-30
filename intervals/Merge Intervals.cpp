// https://neetcode.io/problems/merge-intervals?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) {
            return intervals;
        }
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2){
            if(interval1[0]==interval2[0]) {
                return interval1[1] < interval2[1];
            }
            return interval1[0] < interval2[0];
        });

        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i) {
            int j=res.size()-1;
            if(intervals[i][0]>res[j][1]) {
                res.push_back(intervals[i]);
                continue;
            }
            res[j][1] = max(res[j][1],intervals[i][1]);
        }
        return res;

    }
};
