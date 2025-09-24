//https://neetcode.io/problems/decode-ways?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n);
        if(n==0 || s[0]=='0') {
            return 0;
        }

        dp[0]=1;


        for(int i=1;i<n;++i) {
            if(s[i]=='0'){
                if(s[i-1]>='3'||s[i-1]=='0') {
                    return 0;
                }
                if(i>=2) {
                    // dp[i]=dp[i-1]-dp[i-2]; //?
                    dp[i]=dp[i-2];
                } else {
                    dp[i]=1;
                }
                
            } else if((s[i]>='7' && s[i-1]=='2') || s[i-1]=='0'||s[i-1]>='3') {
                dp[i]=dp[i-1];
            } else {
                if(i>=2) {
                    dp[i]=dp[i-1]+dp[i-2];
                } else {
                    dp[i]=dp[i-1]+1;
                }
                
            }

        }

        return dp[n-1];
    }
};
