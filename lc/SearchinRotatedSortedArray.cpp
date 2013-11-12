class Solution {
public:
	int binarySearch(int A[], int l, int r, int target) {
		int mid;
		while(l < r) {
			mid = l + (r - l) / 2;
			if(A[mid] == target) {
				return mid;
			}
			if(A[mid] >= A[l]) {
				if(target < A[mid] && target >= A[l]) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			} else {
				if(target > A[mid] && target <= A[r]) {
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
		}
		return l;
	}

    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int index = binarySearch(A, 0, n - 1, target);
		if(A[index] == target) {
			return index;
		} else {
			return -1;
		}
    }
};