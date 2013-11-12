#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(const string &s, int begin, int end) {
		while(begin < end) {
			if(s[begin] != s[end]) {
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}

	void getRest(const string &s, int begin, int len, vector<vector<bool> > &p,
		vector<string> &cur, int &mini) {
		if (begin >= len) {
			//ans.push_back(cur);
			mini = min(mini, (int)(cur.size() - 1));
			if(mini == 4) {
				for(int i = 0; i < cur.size(); ++i) {
					printf("%s\n",cur[i].c_str());
				}
			}
			return;
		}
		for(int i = len - 1; i >= begin; --i) {
				if(p[i - begin][begin]) {
						cur.push_back(s.substr(begin, i + 1 - begin));
						getRest(s, i + 1, len, p, cur, mini);
						cur.pop_back();
						break;
					}
		}
	}

	int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
		if(len == 0) {
			return 0;
		}
        vector<vector<bool> > p(len, vector<bool> (len, false));

		for(int i = 0; i < len; ++i) {
			for(int j = 0; (i + j) < len; ++j) {
				if(i == 0) {
					p[i][j] = true;
				} else {
					if((i == 1 || p[i - 2][j + 1]) && s[j] == s[i + j]) {
						p[i][j] = true;
					}
				}
			}
		}
		vector<string> cur;
		int mini = len - 1;
		vector<int> dp(len, mini);
		dp[0] = 0;
		for(int i = 1; i < len; ++i) {
			if(p[i][0]) {
				dp[i] = 0;
			} else {
				int last = dp[i - 1] + 1;
				for(int j = 1; j < i; ++j) {
//					if(dp[j - 1] + 1 >= last) {
//						dp[i] = last;
//						break;
//					}
					if(p[i - j][j]) {
						last = min(last, dp[j - 1] + 1);
					}
				}
				dp[i] = min(dp[i], last);
			}
		}

		//printf("%d\n",dp[len - 1]);
		return dp[len - 1];
		//getRest(s, 0, len, p, cur, mini);
		//return mini;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	s.minCut("ababbbabbaba");
	
	return 0;
}