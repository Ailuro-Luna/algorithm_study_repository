//https://neetcode.io/problems/count-number-of-islands?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) {return 0;}
        int islands_num = 0;
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<bool>> is_visited(row, vector<bool>(column));

        for(int i=0;i<row;i++) {
            for(int j =0;j<column;j++) {
                if(is_visited[i][j] || grid[i][j]=='0') {continue;}
                ++islands_num;

                // begin bfs
                queue<pair<int,int>> data_queue;
                data_queue.push({i,j});

                // cout<<i<<" "<<j<<endl;

                while(!data_queue.empty()) {
                    pair<int,int> point = data_queue.front();
                    data_queue.pop();
                    int x = point.first;
                    int y = point.second;

                    

                    if((x<0) || (x>= row) || (y<0) ||(y>=column)) {
                        continue;
                    }
                    if((is_visited[x][y])|| (grid[x][y]=='0')) {
                        continue;
                    }
                    is_visited[x][y]=true;
                    data_queue.push({x+1,y});
                    data_queue.push({x-1,y});
                    data_queue.push({x,y+1});
                    data_queue.push({x,y-1});
                }
            }
        }
        return islands_num;
    }
};
