class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
		permute(num, ans, 0, num.size());
		return ans;
    }

	void permute(vector<int> &num, vector<vector<int> > &ans, int dep, int len) {
		if(dep == len) {
			ans.push_back(num);
		}
		for(int i = dep; i < len; ++i) {
			swap(num[i], num[dep]);
			permute(num, ans, dep + 1, len);
			swap(num[i], num[dep]);
		}
	}
};