//https://neetcode.io/problems/minimum-stack
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> num_stack;
    stack<int> min_stack;

public:

    MinStack() {
        // stack<int> num_stack = new stack<int>();
    }
    
    void push(int val) {
        num_stack.push(val);
        if(min_stack.empty()) {
            min_stack.push(val);
        } else if (min_stack.top()>=val) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(num_stack.top()==min_stack.top()) {
            min_stack.pop();
        }
        num_stack.pop();
        
    }
    
    int top() {
        return num_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
