//https://neetcode.io/problems/generate-parentheses
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current_str = "";
        backTrack(res,current_str,0,0,n);
        return res;
    }

    void backTrack(vector<string>& res,string & current_str, int l_num, int r_num, int n) {
        if(r_num == n-1 && l_num == n) {
            current_str+=")";
            res.push_back(current_str);
            current_str.pop_back();
            return;
        }

        
        if(l_num<n) {
            current_str += "(";
            ++l_num;
            backTrack(res, current_str, l_num, r_num, n);
            current_str.pop_back();
            --l_num;
        }

        if(r_num<l_num) {
            current_str += ")";
            ++r_num;
            backTrack(res, current_str, l_num, r_num, n);
            current_str.pop_back();
            --r_num;
        }

        return;
    }
};
