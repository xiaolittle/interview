class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s == NULL || p == NULL) {
            return false;
        }
        if(*p == 0) {
            return *s == 0;
        }
        int m = strlen(s);
        int n = strlen(p);
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        
        return isMatch(s, p, dp, 0, 0) == 1;
    }
    
    int isMatch(const char *s,const char *p, vector<vector<int> > &dp,
        int i, int j) {
        if(dp[i][j] != 0) {
            return dp[i][j];
        } else if(s[i] == 0 && p[j] == 0) {
            return dp[i][j] = 1;
        } else if(p[j] == 0) {
            return dp[i][j] = -1;
        }
        dp[i][j] = -1;
        if(s[i] == 0 && p[j] != '*' && p[j + 1] != '*') {
            return dp[i][j] = -1;
        }
        if(p[j + 1] != '*') {
            if((s[i] == p[j] || (s[i] != 0 && p[j] == '.')) && isMatch(s, p, dp, i + 1, j + 1) == 1) {
                return dp[i][j] = 1;
            }
        } else {
            if(isMatch(s, p, dp, i, j + 2) == 1) {
                return dp[i][j] = 1;
            }
            if(s[i] == p[j] || p[j] == '.') {
                while(s[i] != 0 && (s[i] == p[j] || p[j] == '.')) {
                    if(isMatch(s, p, dp, i + 1, j + 2) == 1) {
                        return dp[i][j] = 1;
                    }
                    ++i;
                }
            }
        }
        return dp[i][j];
    }
};
