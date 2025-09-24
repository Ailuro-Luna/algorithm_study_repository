// https://neetcode.io/problems/longest-palindromic-substring?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len<=1) {
            return s;
        }
        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int i=0;i<len-1;++i) {
            dp[i][i] = true;
            dp[i][i+1] = (s[i]==s[i+1]);
        }
        dp[len-1][len-1] = true;

        int max_len=0;
        int max_i;
        
        for(int i=len-1;i>=0;--i) {
            for(int j=i+2;j<len;++j) {
                dp[i][j]=(dp[i+1][j-1])&&(s[i]==s[j]);
            }
        }

        for(int i=0;i<len;++i) {
            for(int j=i;j<len;++j) {
                // cout<<dp[i][j]<<" ";
                if(dp[i][j] && j-i+1>=max_len) {
                    max_len = j-i+1;
                    max_i=i;
                }
            }
            // cout<<endl;
        }
        return s.substr(max_i,max_len);
    }
};
