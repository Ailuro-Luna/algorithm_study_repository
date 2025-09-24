// https://neetcode.io/problems/coin-change?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+2,-1);
        dp[0]=0;

        for(int i=0;i<amount;++i) {
            if(dp[i]==-1) {
                continue;
            }
            for(auto &coin:coins) {
                if( (long long)i+coin>amount) {
                    continue;
                }
                if(dp[i+coin]==-1) {
                    dp[i+coin]=1+dp[i];
                } else {
                    dp[i+coin]=min(dp[i+coin],1+dp[i]);
                }
            }
        }
        return dp[amount];
    }
};
