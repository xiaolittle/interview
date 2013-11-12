class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = S.size();
		int n = T.size();
        if(m < n) {
			return 0;
		}

		vector<vector<int> > dp(m, vector<int> (n, 0));

		int count = 0;
		for(int i = 0; i < m; ++i) {
			if(S[i] == T[0]) {
				++count;
			}
			dp[i][0] = count;
		}

		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				if(S[i] == T[j]) {
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[m - 1][n - 1];
    }
};