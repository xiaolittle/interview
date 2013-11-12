class Solution {
public:
	int lowBinarySearch(int A[], int l, int r, int target) {
		while(l < r) {
			int mid = l + (r - l) / 2;
			if(A[mid] < target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}

    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return lowBinarySearch(A, 0, n, target);
    }
};