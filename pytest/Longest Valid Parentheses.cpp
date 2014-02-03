class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        if(s.size() < 2) {
            return ans;
        }
        stack<char> st;
        int i = 0;
        int cur = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                dp[i] = 0;
            } else {
                int pos = i - 1 - dp[i - 1];
                if(pos >= 0 && s[pos] == '(') {
                    if(pos == 0) {
                        dp[i] = i + 1;
                    } else {
                        dp[i] = i + 1 - pos + dp[pos - 1];
                    }
                } else {
                    dp[i] = 0;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
