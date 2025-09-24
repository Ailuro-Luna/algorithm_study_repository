// https://neetcode.io/problems/islands-and-treasure?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> bfs;
        int m = grid.size();
        if(m==0) { return;}
        int n= grid[0].size();

        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]==0) {
                    bfs.push({i,j});
                }
            }
        }

        while(!bfs.empty()) {
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};
            auto [curr_x, curr_y] = bfs.front();
            bfs.pop();
            for(int i=0;i<4;i++) {
                int next_x = curr_x+dx[i];
                int next_y = curr_y+dy[i];
                if(next_x<0||next_x>=m||next_y<0||next_y>=n||grid[next_x][next_y]==-1) {
                    continue;
                }
                if(grid[next_x][next_y]>grid[curr_x][curr_y]+1) {
                    grid[next_x][next_y] = grid[curr_x][curr_y]+1;
                    bfs.push({next_x,next_y});
                }
            }
        }
        return;
    }
};
