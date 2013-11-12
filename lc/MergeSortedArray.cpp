class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = m + n - 1;
		int i = m - 1;
		int j = n - 1;
		while(cur >= 0) {
			if(i >= 0 && j >= 0) {
				if(A[i] > B[j]) {
					A[cur--] = A[i--];
				} else {
					A[cur--] = B[j--];
				}
			} else if(i >= 0) {
				A[cur--] = A[i--];
			} else {
				A[cur--] = B[j--];
			}
		}
    }
};