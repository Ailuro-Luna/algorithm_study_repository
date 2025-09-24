//https://neetcode.io/problems/rotate-matrix?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // matrix[i][j] -> matrix[j][n-1-i]
    // matrix[j][n-1-i] -> matrix[n-1-i][n-1-j]
    // matrix[n-1-i][n-1-j] -> matrix[n-1-j][i]
    // matrix[n-1-j][i] -> matrix[i][j]

    // literation in layer
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++) {
            for(int j=i;j<n-1-i;j++) {
                int temp = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = temp;
            }
        }
    }
};

