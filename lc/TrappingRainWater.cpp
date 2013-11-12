class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
		int right = n - 1;
		int ans = 0;

		while(left < right) {
			if(A[left] < A[right]) {
				if(A[left] > A[left + 1]) {
					ans += A[left] - A[left + 1];
					A[left + 1] = A[left];
				}
				left++;
			} else {
				if(A[right] > A[right - 1]) {
					ans += A[right] - A[right - 1];
					A[right - 1] = A[right];
				}
				right--;
			}
		}
		return ans;
    }
};