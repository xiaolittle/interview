class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
		map<string, int> mp;
		vector<string> ans;

		for(int i = 0; i < n; ++i) {
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			if(mp.count(cur) > 0) {
				mp[cur]++;
			} else {
				mp[cur] = 1;
			}
		}

		for(int i = 0; i < n; ++i) {
			string cur = strs[i];
			sort(cur.begin(), cur.end());
			if(mp[cur] > 1) {
				ans.push_back(strs[i]);
			}
		}

		return ans;
    }
};