//https://neetcode.io/problems/pacific-atlantic-water-flow?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& bfs_queue, vector<vector<bool>>& to_ocean) {
        int m = heights.size();
        int n = heights[0].size();
        while(!bfs_queue.empty()) {
            auto [r,c] = bfs_queue.front();
            bfs_queue.pop();
            int dr[] = {0,0,-1,+1};
            int dc[] = {-1,+1,0,0};
            for(int i=0;i<4;++i) {
                int next_r=r+dr[i];
                int next_c=c+dc[i];
                if(next_r<0||next_r>=m||next_c<0||next_c>=n||heights[next_r][next_c]<heights[r][c]||to_ocean[next_r][next_c]) {
                    continue;
                }
                to_ocean[next_r][next_c]=true;
                bfs_queue.push({next_r,next_c});
            }
        }
    }
    

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size()==0 || heights[0].size()==0) {
            return {};
        }
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> to_pacific(m, vector<bool>(n));
        vector<vector<bool>> to_atlantic(m, vector<bool>(n));
        queue<pair<int,int>> pacific_bfs;
        queue<pair<int,int>> atlantic_bfs;
        vector<vector<int>> res;

        for(int i=0;i<m;++i) {
            to_pacific[i][0]=true;
            pacific_bfs.push({i,0});
            to_atlantic[i][n-1]=true;
            atlantic_bfs.push({i,n-1});
        }
        for(int j=0;j<n;++j) {
            to_pacific[0][j]=true;
            pacific_bfs.push({0,j});
            to_atlantic[m-1][j]=true;
            atlantic_bfs.push({m-1,j});
        }

        bfs(heights,pacific_bfs,to_pacific);
        bfs(heights,atlantic_bfs,to_atlantic);

        for(int r=0;r<m;++r) {
            for(int c=0;c<n;++c) {
                if(to_pacific[r][c] && to_atlantic[r][c]) {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }
};

