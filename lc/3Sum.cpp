class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
		vector<vector<int> >  ans;
		int len = num.size();
		if(len < 3) {
			return ans;
		}
		int i, j, k;
		for(i = 0; i < len; ) {
			for(j = i + 1, k = len - 1; j < k;) {
				while(j < k && num[i] + num[j] + num[k] < 0) {
					++j;
				}
				if(j == k) {
					break;
				}
				if(num[i] + num[j] + num[k] == 0) {
					vector<int> cur;
					cur.push_back(num[i]);
					cur.push_back(num[j]);
					cur.push_back(num[k]);
					ans.push_back(cur);
				}
				int x = k - 1;
				while(num[k] == num[x] && x > i) {
					x--;
				}
				k = x;
			}
			int x = i + 1;
			while(x < len && num[i] == num[x]) {
				++x;
			}
			i = x;
		}
		return ans;
    }
};