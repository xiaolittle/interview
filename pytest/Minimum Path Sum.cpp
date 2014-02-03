class Solution {
public:
    int minPathSum(vector&lt;vector&lt;int&gt; &gt; &amp;grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if(m == 0) {
            return 0;
        }
        int n = grid[0].size();
        vector&lt;int&gt; last(n);
        vector&lt;int&gt; cur(n);
        last[0] = grid[0][0];
        for(int i = 1; i &lt; n; ++i) {
            last[i] = grid[0][i] + last[i - 1];
        }
        for(int i = 1; i &lt; m; ++i) {
            for(int j = 0; j &lt; n; ++j) {
                if(j == 0) {
                    cur[j] = last[j] + grid[i][j];
                } else {
                    cur[j] = min(last[j], cur[j - 1]) + grid[i][j];
                }
                last[j] = cur[j];
            }
        }
        return last[n - 1];
    }
};