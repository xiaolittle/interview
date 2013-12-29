#include <stdio.h>
#include <stack>

void sortStack(stack<int> &ori) {
    stack<int> tmp;
    while(!ori.empty()) {
        int cur = ori.top();
        ori.pop();
        while(!tmp.empty() && tmp.top() > cur) {
            ori.push(tmp.top());
            tmp.pop();
        }
        tmp.push(cur);
    }
    
}

