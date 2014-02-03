class Solution {
public:
    int dpHelper(vector&lt;vector&lt;int&gt; &gt; &amp;dp, int i, int j, string &amp;s1, string &amp;s2, string &amp;s3) {
        if(dp[i][j] != 0) {
            return dp[i][j];
        }
        if(i == s1.size() && j == s2.size()) {
            return dp[i][j] = 1;
        }
        dp[i][j] = -1;
        if(i < s1.size() && s1[i] == s3[i + j] && dpHelper(dp, i + 1, j, s1, s2, s3) == 1) {
            return dp[i][j] = 1;
        }
        if(j < s2.size() && s2[j] == s3[i + j] && dpHelper(dp, i, j + 1, s1, s2, s3) == 1) {
            return dp[i][j] = 1;
        }
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != (m + n)) {
            return false;
        }
        if(s3.size() == 0) {
            return true;
        } else if(m == 0) {
            return s2 == s3;
        } else if(n == 0) {
            return s1 == s3;
        }
        vector&lt;vector&lt;int&gt; &gt; dp(m + 1, vector&lt;int&gt; (n + 1, 0));
        return dpHelper(dp, 0, 0, s1, s2, s3) == 1;
    }
};
