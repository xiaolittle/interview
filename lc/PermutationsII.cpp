class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
		int n = num.size();
		sort(num.begin(), num.end());
		ans.push_back(num);
		while(true) {
			int pos = n - 1;
			while(pos > 0 && num[pos - 1] >= num[pos]) {
				pos--;
			}
			if(pos == 0) {
				break;
			}
			int pos2 = n - 1;
			while(pos2 > pos && num[pos2] <= num[pos - 1]) {
				pos2--;
			}
			swap(num[pos - 1], num[pos2]);
			reverse(num.begin() + pos, num.end());
			ans.push_back(num);
		}
		return ans;
    }
};