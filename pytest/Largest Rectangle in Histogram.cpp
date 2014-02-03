class Solution {
public:
    int largestRectangleArea(vector&lt;int&gt; &amp;height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        if(n == 0) {
            return 0;
        }
        vector&lt;int&gt; left(n);
        vector&lt;int&gt; right(n);
        stack&lt;int&gt; st;
        for(int i = 0; i &lt; n; ++i) {
            if(i == 0) {
                left[i] = i;
                st.push(i);
            } else {
                while(!st.empty()) {
                    if(height[st.top()] &gt;= height[i]) {
                        st.pop();
                    } else {
                        left[i] = st.top() + 1;
                        break;
                    }
                }
                if(st.empty()) {
                    left[i] = 0;
                }
                st.push(i);
            }
        }
        
        st = stack&lt;int&gt;();
        
        for(int i = n - 1; i &gt;= 0; --i) {
            if(i == (n - 1)) {
                right[i] = n - 1;
                st.push(i);
            } else {
                while(!st.empty()) {
                    if(height[st.top()] &gt;= height[i]) {
                        st.pop();
                    } else {
                        right[i] = st.top() - 1;
                        break;
                    }
                }
                if(st.empty()) {
                    right[i] = n - 1;
                }
                st.push(i);
            }
        }
        int ans = 0;
        for(int i = 0; i &lt; n; ++i) {
            ans = max(ans, (right[i] - left[i] + 1) * height[i]);
        }
        return ans;
    }
};