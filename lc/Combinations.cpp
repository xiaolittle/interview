class Solution {
public:
	void calc(vector<vector<int> > &ans, vector<int> cur, int n, int k, int dep) {
		if(cur.size() == k) {
			ans.push_back(cur);
			return;
		}
		for(int i = dep; i < n; ++i) {
			cur.push_back(i + 1);
			calc(ans, cur, n, k, i + 1);
			cur.pop_back();
		}
	}

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
		vector<int> cur;
		calc(ans, cur, n, k, 0);
		return ans;
    }
};