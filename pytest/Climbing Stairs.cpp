class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; dp(n, 0);
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i &lt; n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};