#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = height.size();
        if(n == 0) {
            return 0;
        }
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                st.push(i);
                left[i] = 0;
            } else {
                while(!st.empty()) {
                    if(height[st.top()] >= height[i]) {
                        st.pop();
                    } else {
                        break;
                    }
                }
                if(st.empty()) {
                    left[i] = 0;
                } else {
                    left[i] = st.top() + 1;
                }
                st.push(i);
            }
        }
        st = stack<int> ();
        int ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(i == n - 1) {
                st.push(i);
                right[i] =  n - 1;
            } else {
                while(!st.empty()) {
                    if(height[st.top()] >= height[i]) {
                        st.pop();
                    } else {
                        break;
                    }
                }
                if(st.empty()) {
                    right[i] = n - 1;
                } else {
                    right[i] = st.top() - 1;
                }
                st.push(i);
            }
            
            ans = max(ans, height[i] * (right[i] + 1 - left[i]));
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a(1, 0);
    int ans = s.largestRectangleArea(a);
    printf("%d\n", ans);

}
