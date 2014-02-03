class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n &lt; 2) {
            return 0;
        }
        vector&lt;vector&lt;bool&gt; &gt; isPalin(n, vector&lt;bool&gt; (n, false));
        
        for(int i = 0; i &lt; n; ++i) {
            isPalin[i][i] = true;
        }
        for(int len = 1; len &lt; n; ++len) {
            for(int i = 0; i + len &lt; n; ++i) {
                if(len == 1) {
                    isPalin[i][i + len] = (s[i] == s[i + len]);
                } else {
                    isPalin[i][i + len] = (s[i] == s[i + len]) &amp;&amp; isPalin[i + 1][i + len - 1];
                }
            }
        }
        
        vector&lt;int&gt; dp(n, n - 1);
        dp[0] = 0;
        for(int i = 1; i &lt; n; ++i) {
            if(isPalin[0][i]) {
                dp[i] = 0;
            } else {
                int last = dp[i - 1] + 1;
                for(int j = 1; j &lt; i; ++j) {
                    if(isPalin[j][i]) {
                        last = min(last, isPalin[j][i] + dp[j - 1]);
                    }
                }
                dp[i] = min(dp[i], last);
            }
        }
        return dp[n - 1];
        
    }
};