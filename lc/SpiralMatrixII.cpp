class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > matrix(n, vector<int> (n, 0));
		if(n <= 0) {
			return matrix;
		}
		int left = 0;
		int right = n - 1;
		int low = 0;
		int high = n - 1;
		int count = 1;
		while(true) {
			if(left > right) {
				break;
			}
			for(int i = left; i <= right; ++i) {
				matrix[low][i] = count++;
			}
			low++;
			if(low > high) {
				break;
			}
			for(int i = low; i <= high; ++i) {
				matrix[i][right] = count++;
			}
			right--;
			if(left > right) {
				break;
			}
			for(int i = right; i >= left; --i) {
				matrix[high][i] = count++;
			}
			high--;
			if(low > high) {
				break;
			}
			for(int i = high; i >= low; --i) {
				matrix[i][left] = count++;
			}
			left++;
		}
		return matrix;
    }
};