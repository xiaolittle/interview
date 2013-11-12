class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
		if(len < 3) {
			return -1;
		}
		sort(num.begin(), num.end());
		int mini = num[0] + num[1] + num[2];
		int i,j,k;
		for(i = 0; i < len; ++i) {
			for(j = i + 1, k = len - 1; j < k; --k) {
				while(j < k && num[i] + num[j] + num[k] < target) {
					++j;
				}
				if(j < k) {
					if(abs(num[i] + num[j] + num[k] - target) < abs(mini - target)) {
						mini = num[i] + num[j] + num[k];
					}
				}
			}
		}
		return mini;
    }
};