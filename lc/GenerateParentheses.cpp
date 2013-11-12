class Solution {
public:
	void generateParenthesis(int left, int right, int dep, vector<string> &ans, string cur, int len) {
		if(left < 0 || right < 0 || left > right) {
			return;
		}
		if(dep == 2*len) {
			ans.push_back(cur);
			return;
		}
		if(left > 0) {
			cur += "(";
			generateParenthesis(left - 1, right, dep + 1, ans, cur, len);
			cur.erase(cur.size() - 1, 1);
		}
		if(right > 0) {
			cur += ")";
			generateParenthesis(left, right - 1, dep + 1, ans, cur, len);
			cur.erase(cur.size() - 1, 1);
		}
	}

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
		if(n == 0) {
			return ans;
		}
		string cur = "";
		generateParenthesis(n, n, 0, ans, cur, n);
		return ans;
    }
};