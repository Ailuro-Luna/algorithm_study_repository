// https://neetcode.io/problems/search-2d-matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        // find row
        int up=0;
        int down = m-1;
        int middle = up+(down-up)/2;
        while(down-up>=1) {
            if(matrix[middle][0]>target) {
                down = middle -1;
            } else if(matrix[middle][n-1]<target) {
                up = middle +1;
            } else {
                break;
            }
            middle = up+(down-up)/2;
        }
        // cout<<middle<<endl;

        int l = 0;
        int r=n-1;
        int center = l+(r-l)/2;
        // cout<<middle<<endl;
        while(l<r) {
            // cout<<l<<" "<<r<<endl;
            if(matrix[middle][center]>target) {
                r = center -1;
            } else if(matrix[middle][center]<target) {
                l = center +1;
            } else {
                return true;
            }
            center = l+(r-l)/2;
        }
        if(matrix[middle][center]==target) {
            return true;
        }
        return false;
    }
};
