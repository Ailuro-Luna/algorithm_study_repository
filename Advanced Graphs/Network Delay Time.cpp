//https://neetcode.io/problems/network-delay-time?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

class Solution {

/*
dij
priority_queue


*/

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int minimum_time = -1;
        priority_queue<pii, vector<pii>, greater<pii>> next_nodes;
        vector<int> dist(n+1);    // distance between k and i
        vector<vector<pii>> adj_list(n+1);

        // init adj_list

        for(const auto &time:times) {
            adj_list[time[0]].push_back({time[1],time[2]});
        }

        // init dist
        for(int i=1;i<=n;i++) {
            dist[i] = numeric_limits<int>::max();
        }
        dist[k]=0;

        next_nodes.push({0,k});

        while(!next_nodes.empty()) {
            int d = next_nodes.top().first;
            int u = next_nodes.top().second;
            next_nodes.pop();
            if(d>dist[u]) {
                continue;
            }
            for(auto &pair:(adj_list[u])) {
                int neighbor = pair.first;
                if(dist[neighbor]>dist[u]+pair.second) {
                    dist[neighbor]=dist[u]+pair.second;
                    next_nodes.push({dist[neighbor],neighbor});
                }
            }
        }

        
        for(int i=1;i<=n;i++) {
            minimum_time = max(minimum_time,dist[i]);
        }

        if(minimum_time ==numeric_limits<int>::max()) {
            minimum_time = -1;
        }

        return minimum_time;
    }
};
