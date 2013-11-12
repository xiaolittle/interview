class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxi = 0;
		int i = 0;
		while(i <= maxi) {
			maxi = max(maxi, i + A[i]);
			if(maxi >= n - 1) {
				return true;
			}
			++i;
		}
		return false;
    }
};