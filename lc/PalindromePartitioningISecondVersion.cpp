class Solution {
public:
	void getRest(const string &s, int begin, int len, vector<vector<bool> > &p,
		vector<string> &cur, vector<vector<string> > &ans, int &mini) {
		if (begin >= len) {
			ans.push_back(cur);
			mini = min(mini, (int)(cur.size() - 1));
			return;
		}
		for(int i = len - 1; i >= begin; --i) {
				if(p[i - begin][begin]) {
						cur.push_back(s.substr(begin, i + 1 - begin));
						getRest(s, i + 1, len, p, cur, ans, mini);
						cur.pop_back();
						//break;
					}
		}
	}
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
		vector<vector<string> > ans;
		if(len == 0) {
			return ans;
		}
        vector<vector<bool> > p(len, vector<bool> (len, false));
//		for(int i = 0; i < len; ++i) {
//			for(int j = i; j < len; ++j) {
//				if(i == j) {
//					p[i][j] = true;
//				} else {
//					p[i][j] = isPalindrome(s, i, j); 
//				}
//			}
//		}

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
		int mini = s.size() - 1;
		getRest(s, 0, len, p, cur, ans, mini);
		return ans;
    }
};