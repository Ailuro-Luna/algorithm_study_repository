// https://neetcode.io/problems/evaluate-reverse-polish-notation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> data_stack;
        for(auto &token:tokens) {
            if((token[0]<='9' && token[0]>='0')||token.length()>=2) {
                data_stack.push(stoi(token));
                continue;
            }
            int suf_num = data_stack.top();
            data_stack.pop();
            int pre_num = data_stack.top();
            data_stack.pop();
            int res;
            if(token[0] == '+') {res=pre_num+suf_num;}
            if(token[0] == '-') {res=pre_num-suf_num;}
            if(token[0] == '*') {res=pre_num*suf_num;}
            if(token[0] == '/') {res=pre_num/suf_num;}
            data_stack.push(res);
            cout<<pre_num<<" "<<suf_num<<endl;
            cout<<token[0]<<" "<<res<<endl;
        }
        return data_stack.top();
    }
};
