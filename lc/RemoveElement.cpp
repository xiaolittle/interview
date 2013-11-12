#include <stdio.h>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int count = 0;
		for(int i = 0; i < n; ++i) {
			if(A[i] == elem) {
				continue;
			} else {
				A[count++] = A[i];
			}
		}
		return count;
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
