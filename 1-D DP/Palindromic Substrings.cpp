//https://neetcode.io/problems/palindromic-substrings?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int num = 0;
        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int i=0;i<len-1;i++) {
            dp[i][i]=true;
            ++num;
            dp[i][i+1]=(s[i]==s[i+1]);
            if(dp[i][i+1]) {
                ++num;
            }
        }
        dp[len-1][len-1]=true;
        ++num;

        for(int L=3;L<=len;++L) {
            for(int i=0;i+L<=len;++i) {
                int j=i+L-1;
                dp[i][j]=(dp[i+1][j-1]&&s[i]==s[j]);
                if(dp[i][j]) {
                    ++num;
                }
            }
        }
        return num;
    }
};
