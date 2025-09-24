//https://neetcode.io/problems/rotting-fruit?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) {
            return 0;
        }
        int n =grid[0].size();

        queue<pair<int,int>>bfs;
        int fresh_num=0;
        int time_step = -1;

        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==1) {
                    ++fresh_num;
                } else if(grid[i][j]==2) {
                    bfs.push({i,j});
                }
            }
        }
        while(!bfs.empty()){
            for(int rotten_num = bfs.size();rotten_num>0;--rotten_num) {
                auto [curr_x,curr_y] = bfs.front();
                bfs.pop();

                int dx[] = {0,0,1,-1};
                int dy[] = {1,-1,0,0};

                for(int i=0;i<4;++i) {
                    int next_x = curr_x+dx[i];
                    int next_y = curr_y+dy[i];
                    if(next_x<0 || next_x>=m ||next_y<0 ||next_y>=n || grid[next_x][next_y]!=1) {
                        continue;
                    }
                    --fresh_num;
                    grid[next_x][next_y] = 2;
                    bfs.push({next_x,next_y});
                }
            }
            ++time_step;
        }
        if(fresh_num!=0) {
            return -1;
        }
        if(time_step==-1) {
            return 0;
        }
        return time_step;
    }
};
