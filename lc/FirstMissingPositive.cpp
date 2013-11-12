#include <stdio.h>

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = 0;
		int last = 0;
		while(true) {
			while(last < n && (A[last] == last + 1 || A[last] <= 0 || A[last] > n)) {
				++last;
			}
			if(last >= n) {
				break;
			}
			if(A[last] != last + 1) {
				cur = last;
				int tmp = A[cur];
				while(cur >= 0 && cur < n && A[cur] != cur + 1) {
					//printf("tmp = %d,cur = %d\n",tmp, cur);
					if(A[tmp - 1] == tmp) {
						++last;
						break;
					}
					cur = A[tmp - 1] - 1;
					A[tmp - 1] = tmp;
					tmp = cur + 1;
					//printf("hahaha:tmp = %d,cur = %d\n",tmp, cur);
				}
			}
		}
		int i = 0;
		for(; i < n; ++i) {
			//printf("A[%d] = %d\n",i, A[i]);
			if(A[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	int A[6] = {-1, 4, 2, 1, 9, 10};
	s.firstMissingPositive(A, 6);
	
	return 0;
}