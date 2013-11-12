class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) {
			return 1;
		}
        for(int i = 0; i < n;) {
			int pos = A[i];
			while(pos > 0 && pos <= n && A[pos - 1] != pos) {
				int tmp = A[pos - 1];
				A[pos - 1] = pos;
				pos = tmp;
			}
			++i;
			while(i < n && (A[i] == i + 1 || A[i] <= 0 || A[i] > n)) {
				++i;
			}
		}

		for(int i = 0; i < n; ++i) {
			if(A[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
    }
};