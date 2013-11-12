class Solution {
public:
	int lowBound(int A[], int l, int r, int target) {
		int mid;
		while(l < r) {
			mid = l + (r - l) / 2;
			if(A[mid] < target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}

	int highBound(int A[], int l, int r, int target) {
		int mid;
		while(l < r) {
			mid = l + (r - l) / 2;
			if(A[mid] <= target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = lowBound(A, 0, n, target);
		int high = highBound(A, 0, n, target);
		vector<int> ans;
		if(low == high) {
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		} else {
			ans.push_back(low);
			ans.push_back(high - 1);
			return ans;
		}
    }
};