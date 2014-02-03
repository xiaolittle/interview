class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; last(n, 1);
        for(int i = 1; i &lt; m; ++i) {
            vector&lt;int&gt; cur(n);
            for(int j = 0; j &lt; n; ++j) {
                if(j == 0) {
                    cur[j] = 1;
                } else {
                    cur[j] = cur[j - 1] + last[j];
                }
            }
            last = cur;
        }
        return last[n - 1];
    }
};