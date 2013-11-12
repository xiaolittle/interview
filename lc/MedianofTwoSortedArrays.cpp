class Solution {
public:
	double findKHelper(int A[], int m, int B[], int n, int k, bool needtwo) {
		int left = k < (n + 1) ? 0 : k - n - 1;
		int right = k > m - 1 ? m - 1 : k - 1;

		while(left <= right) {
			int mid = (left + right) / 2;
			int pre = k - mid - 2 >= 0 ? B[k - mid - 2] : numeric_limits<int>::min();
			int back = k - mid - 1 < n ? B[k - mid - 1] : numeric_limits<int>::max();
			if(A[mid] >= pre && A[mid] <= back) {
				if(needtwo) {
					int first = A[mid];
					if((mid + 1) < m && A[mid + 1] <= back) {
						return (first + A[mid + 1]) / 2.0;
					} else {
						return (first + back) / 2.0;
					}
				} else {
					return A[mid];
				}
			}
			if(A[mid] < pre) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}

	double findKElement(int A[], int m, int B[], int n, int k, bool needtwo) {
		if(n == 0) {
			if(needtwo) {
				return (A[k - 1] + A[k]) / 2.0;
			} else {
				return A[k - 1];
			}
		} else if(m == 0) {
			if(needtwo) {
				return (B[k - 1] + B[k]) / 2.0;
			} else {
				return B[k - 1];
			}
		}
		double tmp = findKHelper(A, m, B, n, k, needtwo);
		if(tmp < 0) {
			return findKHelper(B, n, A, m, k, needtwo);
		}
		return tmp;
	}
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(m == 0 && n == 0) {
			return 0;
		}
        if((m + n) % 2 != 0) {
			return findKElement(A, m , B, n, (m + n) / 2 + 1, false);
		} else {
			return findKElement(A, m, B, n, (m + n) / 2, true);
		}
    }
};