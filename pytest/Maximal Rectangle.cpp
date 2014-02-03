class Solution {
public:
    int calcThisLine(vector&lt;int&gt; &amp;line) {
        int ans = 0;
        int n = line.size();
        vector&lt;int&gt; left(n, 0);
        vector&lt;int&gt; right(n, 0);
        stack&lt;int&gt; st;
        for(int i = 0; i &lt; n; ++i) {
            while(!st.empty()) {
                if(line[st.top()] &gt;= line[i]) {
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
        st = stack&lt;int&gt;();
        for(int i = n - 1; i &gt;= 0; --i) {
            while(!st.empty()) {
                if(line[st.top()] &gt;= line[i]) {
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
        
        for(int i = 0; i &lt; n; ++i) {
            ans = max(ans, line[i] * (right[i] + 1 - left[i]));
        }
        return ans;
    }
    
    int maximalRectangle(vector&lt;vector&lt;char&gt; &gt; &amp;matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int ans = 0;
        if(m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        vector&lt;vector&lt;int&gt; &gt; h(m , vector&lt;int&gt; (n, 0));
        for(int i = 0; i &lt; m; ++i) {
            for(int j = 0; j &lt; n; ++j) {
                if(matrix[i][j] == &#39;0&#39;) {
                    h[i][j] = 0;
                } else {
                    if(i == 0) {
                        h[i][j] = 1;
                    } else {
                        h[i][j] = 1 + h[i - 1][j];
                    }
                }
            }
            ans = max(ans, calcThisLine(h[i]));
        }
        return ans;
    }
};