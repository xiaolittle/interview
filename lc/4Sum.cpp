class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,l;
		int n = num.size();
		sort(num.begin(), num.end());
		vector<vector<int> > ans;
		if(n < 4) {
			return ans;
		}
		for(i = 0; i < n; ) {
			int cur = target - num[i];
			for(j = i + 1; j < n; ) {
				for(k = j + 1, l = n - 1; k < l; l = n - 1) {
					while(k < l && (num[j] + num[k] + num[l]) > cur) {
						--l;
					}
					if(k == l) {
						break;
					}
					if(num[j] + num[k] + num[l] == cur) {
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[k]);
						tmp.push_back(num[l]);
						ans.push_back(tmp);
					}
					int x = k + 1;
					while(x < n && num[k] == num[x]) {
						++x;
					}
					k = x;
				}
				int x = j + 1;
				while(x < n && num[j] == num[x]) {
					++x;
				}
				j = x;
			}
			int x = i + 1;
			while(x < n && num[i] == num[x]) {
				++x;
			}
			i = x;
		}

		return ans;
    }
};