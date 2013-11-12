class Solution {
public:
	void calc(vector<int> &candidates, int target, 
		vector<vector<int> > &ans, int sum, int index, vector<int> cur) {
		if(sum == target) {
			ans.push_back(cur);
		} else if(sum > target) {
			return;
		}
		int len = candidates.size();
		for(int i = index; i < len; ) {
			cur.push_back(candidates[i]);
			calc(candidates, target, ans, sum + candidates[i], i + 1, cur);
			cur.pop_back();
			int j = i + 1;
			while(j < len && candidates[j] == candidates[i]) {
				++j;
			}
			i = j;
		}
	}

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
		int sum = 0;
		vector<vector<int> > ans;
		vector<int> cur;
		calc(candidates, target, ans, sum, 0, cur);
		return ans;
    }
};