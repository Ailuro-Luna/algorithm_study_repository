//https://neetcode.io/problems/surrounded-regions?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) {
            return;
        }
        int n=board[0].size();

        queue<pair<int,int>>bfs;

        for(int i=0;i<m;++i) {
            if(board[i][0]=='O') {
                bfs.push({i,0});
            }
            if(board[i][n-1]=='O') {
                bfs.push({i,n-1});
            }
        }

        for(int j=0;j<n;++j) {
            if(board[0][j]=='O') {
                bfs.push({0,j});
            }
            if(board[m-1][j]=='O') {
                bfs.push({m-1,j});
            }
        }

        while(!bfs.empty()) {
            auto [x,y]=bfs.front();
            bfs.pop();
            board[x][y]='!';
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int i=0;i<4;++i){
                int curr_x=x+dx[i];
                int curr_y=y+dy[i];
                if(curr_x<0||curr_x>=m||curr_y<0||curr_y>=n||board[curr_x][curr_y]!='O') {
                    continue;
                }
                bfs.push({curr_x,curr_y});
            }
        }

        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(board[i][j]=='O') {
                    board[i][j]='X';
                } else if(board[i][j]=='!') {
                    board[i][j]='O';
                }
            }
        }



    }
};
