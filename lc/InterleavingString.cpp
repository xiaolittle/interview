#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int calc(vector<vector<int> > &dp, int i, int j, const string &s1, const string &s2, const string &s3) {
		if(dp[i][j] != 0) {
			return dp[i][j];
		}

		//printf("%d,%d,%d,%d\n",i, j, s1.size(), s2.size());

		if(i == s1.size() && j == s2.size()) {
			dp[i][j] = 1;
			return 1;
		}

		if(i < s1.size() && s1[i] == s3[i + j]) {
			if(calc(dp, i + 1, j, s1, s2, s3) == 1) {
				return dp[i][j] = 1;
			}
		}

		if(j < s2.size() && s2[j] == s3[i + j]) {
			if(calc(dp, i, j + 1, s1, s2, s3) == 1) {
				return dp[i][j] = 1;
			}
		}

		return dp[i][j] = -1;
	}

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if((s1.size() + s2.size()) != s3.size()) {
			return false;
		}
		if(s1.size() == 0 && s2.size() == 0 && s3.size() == 0) {
			return true;
		}

		vector<vector<int> > dp(s1.size() + 1, vector<int> (s2.size() + 1, 0)); 

		if(calc(dp, 0, 0, s1, s2, s3) == 1) {
			return true;
		}
		return false;
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	Solution s;
	string a = "a";
	string b = "";
	string c = "c";
	string d = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	string e = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	printf("%d\n",d.size());
	s.isInterleave(a, b , c);
	return 0;
}