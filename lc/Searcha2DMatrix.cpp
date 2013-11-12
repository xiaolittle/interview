class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
		if(m == 0) {
			return false;
		}
		int n = matrix[0].size();
		if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
			return false;
		}
		int low = 0;
		int high = m;
		while(low < high) {
			int mid = low + (high - low) / 2;
			if(matrix[mid][0] <= target) {
				low = mid + 1;
			} else {
				high = mid; 
			}
		}
		int row = high - 1;
		low = 0;
		high = n;
		while(low < high) {
			int mid = low + (high - low) / 2;
			if(matrix[row][mid] < target) {
				low = mid + 1;
			} else {
				high = mid; 
			}
		}
		if(high >= n || matrix[row][high] != target) {
			return false;
		}
		return true;
    }
};