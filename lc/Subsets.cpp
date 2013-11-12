class Solution {
public:
	void getSubsets(vector<vector<int> > &ans, vector<int> cur, int begin, int len, vector<int> &S) {
		ans.push_back(cur);
		if(begin >= len) {
			return;
		}
		for(int i = begin; i < len;) {
			cur.push_back(S[i]);
			getSubsets(ans, cur, i + 1, len, S);
			cur.pop_back();
			int x = i + 1;
			while(x < len && S[i] == S[x]) {
				++x;
			}
			i = x;
		}
	}

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		sort(S.begin(), S.end());
        vector<vector<int> > ans;
		vector<int> cur;
		getSubsets(ans, cur, 0, S.size(), S);
		return ans;
    }
};