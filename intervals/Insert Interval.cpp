// https://neetcode.io/problems/insert-new-interval?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res(0);
        vector<int> current(newInterval);

        bool has_passed = false;

        for(const auto& interval:intervals) {
            cout<<interval[0]<<" "<<interval[1]<<" "<<current[0]<<" "<<current[1]<<endl;
            if(interval[1]<current[0]) {
                res.push_back(interval);
                continue;
            } else if(interval[0]>current[1]) {
                if(!has_passed) {
                    has_passed = true;
                    res.push_back(current);
                }
                res.push_back(interval);
                continue;
            }
            if(interval[1]>=current[0] && interval[0]<current[0]) {
                current[0] = interval[0];
            }
            if(interval[0]<=current[1] && interval[1]>current[1]) {
                current[1] = interval[1];
            }
            

        }
        if(!has_passed) {
            has_passed = true;
            res.push_back(current);
        }
        return res;
    }
};
