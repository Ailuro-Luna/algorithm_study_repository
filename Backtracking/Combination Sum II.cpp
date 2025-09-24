//https://neetcode.io/problems/combination-target-sum-ii?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();++i) {
            cout<<candidates[i]<<" ";
        }
        cout<<endl;
        back_tracking(candidates, res, current, 0, 0, target);
        return res;
    }

    void back_tracking(vector<int>& candidates, vector<vector<int>> & res, vector<int> & current, int current_val, int idx, int target) {
        if(current_val==target) {
            res.push_back(current);
            return;
        }
        if(idx == candidates.size() || current_val+candidates[idx]>target) {
            return;
        }
        for(int i=idx;i<candidates.size();i++) {
            if(i>idx && candidates[i]== candidates[i-1]) {
                continue;
            }
            current.push_back(candidates[i]);;
            current_val+=candidates[i];
            back_tracking(candidates, res, current, current_val, i+1, target);
            current.pop_back();
            current_val-=candidates[i];
        }
    }
};
