#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p, vector<vector<bool> > &visit, vector<vector<bool> > &dp,
		int i, int j) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(visit[i][j]) {
			return dp[i][j];
		}
        if(*s == 0 && *p == 0) {
			visit[i][j] = true;
			dp[i][j] = true;
			return true;
		}
		if(*p == 0) {
			visit[i][j] = true;
			if(*s == 0) {
				dp[i][j] = true;
				return true;
			}
			return false;
		}
		if(*s == 0) {
			if(*p == '*' && isMatch(s, p + 1, visit, dp, i, j + 1)) {
				visit[i][j] = true;
				dp[i][j] = true;
				return true;
			} else {
				visit[i][j] = true;
				return false;
			}
		}

		if(*p != '*') {
			if ((*p == '?' || *s == *p) && isMatch(s + 1, p + 1, visit, dp, i + 1, j + 1)) {
				visit[i][j] = true;
				dp[i][j] = true;
				return true;
			} else {
				visit[i][j] = true;
				return false;
			}
		} else {
			int k = i;
			while(*s != 0) {
				if(isMatch(s + 1, p + 1, visit, dp, k + 1, j + 1) || isMatch(s, p + 1, visit, dp, k, j + 1)) {
					visit[i][j] = true;
					dp[i][j] = true;
					return true;
				}
				++s;
				++k;
			}
		}
		visit[i][j] = true;
		return false;
    }

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0 && *p == 0) {
			return true;
		}
		if(*p == 0) {
			return *s == 0;
		}
		int slen = strlen(s);
		int plen = strlen(p);

		vector<vector<bool> > visit(slen + 1, vector<bool> (plen + 1, false));
		vector<vector<bool> > dp(slen + 1, vector<bool> (plen + 1, false));

		return isMatch(s, p, visit, dp, 0, 0);
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	s.isMatch("aa", "*");
	
	return 0;
}