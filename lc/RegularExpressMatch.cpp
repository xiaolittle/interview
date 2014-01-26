class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == NULL || p == NULL) {
            return false;
        }
        if (*p == 0) {
            return *s == 0;
        }
        int n = strlen(s);
        int m = strlen(p);
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        return isMatch(s, p, 0, 0, dp) == 1;


    }

    int isMatch(const char *s,
                 const char *p,
                 int i, int j,
                 vector<vector<int> > &dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        } else if (s[i] == 0 && p[j] == 0) {
            return dp[i][j] = 1;
        } else if (p[j] == 0) {
            if (s[i] != 0) {
                dp[i][j] = -1;
            } else {
                dp[i][j] = 1;
            }
            return dp[i][j];
        }

        dp[i][j] = -1;
        if (p[j] != '.') {
            if (p[j + 1] != '*') {
                if (s[i] == p[j] && isMatch(s, p, i + 1, j + 1, dp) == 1) {
                    dp[i][j] = 1;
                }
            } else {
                for (int k = i; ; ++k) {
                    if (isMatch(s, p, k, j + 2, dp) == 1) {
                        dp[i][j] = 1;
                        break;
                    }
                    if (s[k] == 0 || s[k] != p[j]) {
                        break;
                    }
                }
            }
        } else {
            if (p[j + 1] != '*') {
                if (s[i] != 0 && isMatch(s, p, i + 1, j + 1, dp) == 1) {
                    dp[i][j] = 1;
                }
            } else {
                for (int k = i; ; ++k) {
                    if (isMatch(s, p, k, j + 2, dp) == 1) {
                        dp[i][j] = 1;
                        break;
                    }
                    if (s[k] == 0) {
                        break;
                    }
                }
            }
        }
        return dp[i][j];
    }

};
