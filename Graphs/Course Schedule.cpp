// https://neetcode.io/problems/course-schedule?list=neetcode150
#include <bits/stdc++.h>
using namespace std;

class Solution {

/*
Kahn

in-degree

vector<int> degrees;
vector<vector<int>> children;
queue<int> zero_degree_node;



*/

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> children(numCourses);
        vector<int> in_degrees(numCourses);
        queue<int> zero_degree_nodes;
        queue<int> schedule_nodes;

        // init
        for(auto prerequisite:prerequisites) {
            int child = prerequisite[0];
            int parent = prerequisite[1];
            children[parent].push_back(child);
            ++in_degrees[child];
        }

        for(int i =0;i<numCourses;i++) {
            if(in_degrees[i]==0) {
                zero_degree_nodes.push(i);
            }
        }

        while(!zero_degree_nodes.empty()) {
            int current_node = zero_degree_nodes.front();
            zero_degree_nodes.pop();

            for(auto &child:children[current_node]) {
                --in_degrees[child];
                if(in_degrees[child]==0) {
                    zero_degree_nodes.push(child);
                }
            }

            schedule_nodes.push(current_node);
        }

        if(schedule_nodes.size()==numCourses) {
            return true;
        } else {
            return false;
        }
    }
};
