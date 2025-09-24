//https://neetcode.io/problems/eating-bananas
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1;
        int l_speed = 1;
        int r_speed;

        long cost_time = 1000000001;
        while(cost_time>h) {
            cost_time = 0;
            for(auto &pile : piles) {
                cost_time += (pile+speed-1)/speed;
            }
            if(cost_time>h) { // too slow
                speed*=2;
            } 
        }
        r_speed = speed;
        speed = (l_speed+r_speed)/2;

        while(l_speed<r_speed) {
            cost_time = 0;
            for(auto &pile : piles) {
                cost_time += (pile+speed-1)/speed;
            }
            if(cost_time>h) { // too slow
                l_speed=speed+1;
            } else {
                r_speed=speed-1;
            }
            speed = (l_speed+r_speed)/2;
        }

        for(speed=l_speed;;++speed) {
            cost_time = 0;
            for(auto &pile : piles) {
                cost_time += (pile+speed-1)/speed;
            }
            if(cost_time<=h) {
                return speed;
            }
        }

        return speed;

    }
};
