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
		vector<string> cur, vector<vector<string> > &ans) {
		if (begin >= len) {
			ans.push_back(cur);
			return;
		}
		for(int i = begin; i < len; ++i) {
				if(p[begin][i]) {
//					if(i == len - 1) {
//						vector<string> cur;
//						cur.push_back(s.substr(begin, j + 1 - i));
//						ans.push_back(cur);
//					} else {
						cur.push_back(s.substr(begin, i + 1 - begin));
						getRest(s, i + 1, len, p, cur, ans);
						cur.pop_back();
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
		for(int i = 0; i < len; ++i) {
			for(int j = i; j < len; ++j) {
				if(i == j) {
					p[i][j] = true;
				} else {
					p[i][j] = isPalindrome(s, i, j); 
				}
			}
		}
		vector<string> cur;
		getRest(s, 0, len, p, cur, ans);
		return ans;
    }
};