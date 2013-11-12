class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
		int len = height.size();
		int l = 0;
		int r = len - 1;
		if(len < 2) {
			return 0;
		}
		while(l < r) {
			int cur = min(height[l], height[r]) * (r - l);
			if(cur > max) {
				max = cur;
			}
			if(height[l] < height[r]) {
				++l;
			} else {
				--r;
			}
		}
		return max;
    }
};