class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) {
			return 0;
		}
		int last = A[0];
		int ans = last;
		for(int i = 1; i < n; ++i) {
			if(last > 0) {
				last += A[i];
			} else {
				last = A[i];
			}
			ans = max(ans, last);
		}
		return ans;
    }
};