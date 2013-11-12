class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int maxi = 0;
		int n = s.size();
		if(n < 2) {
			return maxi;
		}
		int cur = 0;
		vector<int> dp(n, 0);
		for(int i = 1; i < n; ++i) {
			if(s[i] == ')') {
				if(s[i - 1 - dp[i - 1]] == '(') {
					dp[i] = 2 + dp[i - 1];
					if(i - 1 - dp[i - 1] > 0) {
						dp[i] += dp[i - 1 - dp[i - 1] - 1];
					}
					maxi = max(maxi, dp[i]);
				}
			}
		}
		if(cur > maxi) {
			maxi = cur;
		}
		return maxi;
    }
};