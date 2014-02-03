class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size();
        int n = T.size();
        if(m == 0 || n == 0 || m &lt; n) {
            return 0;
        }
        vector&lt;vector&lt;int&gt; &gt; dp(m, vector&lt;int&gt; (n));
        int count = 0;
        for(int i = 0; i &lt; m; ++i) {
            if(S[i] == T[0]) {
                ++count;
            }
            dp[i][0] = count;
        }
        
        for(int i = 1; i &lt; m; ++i) {
            for(int j = 1; j &lt;= i &amp;&amp; j &lt; n; ++j) {
                if(S[i] == T[j]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};