class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n <= 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            if(s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(val == 0 || (s[i - 1] == '0' && s[i - 2] > '2')) {
                return 0;
            }
            if(s[i - 2] != '0' && val > 0 && val <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
