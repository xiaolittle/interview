class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
		int cur;
		for(int i = 0; i < n; i = cur) {
			cur = i + 1;
			int val = A[i];
			while(cur < n && val == A[cur]) {
				cur++;
			}
			A[len++] = val;
		}
		return len;
    }
};