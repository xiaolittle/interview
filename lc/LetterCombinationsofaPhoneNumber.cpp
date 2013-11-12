class Solution {
public:
	void calc(string &digits, string cur, vector<string> &ans, int dep, vector<string> &alph) {
		if(dep == digits.size()) {
			ans.push_back(cur);
			return;
		}
		for(int i = 0; i < alph[digits[dep] - '2'].size(); ++i) {
			calc(digits, cur + alph[digits[dep] - '2'][i], ans, dep + 1, alph);
		}
	}

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> ans;
		string cur;
		vector<string> alph(8);
		alph[0] = "abc";
		alph[1] = "def";
		alph[2] = "ghi";
		alph[3] = "jkl";
		alph[4] = "mno";
		alph[5] = "pqrs";
		alph[6] = "tuv";
		alph[7] = "wxyz";
		calc(digits, cur, ans, 0, alph);
		return ans;
    }
};