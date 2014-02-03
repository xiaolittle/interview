class Solution {
public:
    int uniquePathsWithObstacles(vector&lt;vector&lt;int&gt; &gt; &amp;obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if(m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector&lt;int&gt; last(n);
        last[0] = 1;
        for(int i = 1; i &lt; n; ++i) {
            if(obstacleGrid[0][i] == 1) {
                last[i] = 0;
            } else {
                last[i] = last[i - 1];
            }
        }
        for(int i = 1; i &lt; m; ++i) {
            vector&lt;int&gt; cur(n);
            for(int j = 0; j &lt; n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                } else if(j == 0) {
                    cur[j] = last[j];
                } else {
                    cur[j] = cur[j - 1] + last[j];
                }
            }
            last = cur;
        }
        return last[n - 1];
    }
};