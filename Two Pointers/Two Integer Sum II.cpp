// https://neetcode.io/problems/two-integer-sum-ii
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int diff;
        for(int i =0;i<numbers.size();++i) {
            diff = target - numbers[i];
            for(int j=i+1;j<numbers.size();++j) {
                if (numbers[j]==diff) {return {i+1,j+1};}
            }
        }

        return {};
    }
};
