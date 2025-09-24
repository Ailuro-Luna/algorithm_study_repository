//https://neetcode.io/problems/count-paths?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n));
        int dp[101][101];
        dp[0][0]=1;
        for(int i=1;i<m;++i) {
            dp[i][0]=1;
        }
        for(int i=1;i<n;++i) {
            dp[0][i]=1;
        }
        for(int i=1;i<m;++i) {
            for(int j=1;j<n;++j) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
