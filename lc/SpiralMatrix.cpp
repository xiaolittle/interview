class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ans;
        int m = matrix.size();
		if(m <= 0) {
			return ans;
		}
		int n = matrix[0].size();
		int left = 0;
		int right = n - 1;
		int low = 0;
		int high = m - 1;
		while(true) {
			if(left > right) {
				break;
			}
			for(int i = left; i <= right; ++i) {
				ans.push_back(matrix[low][i]);
			}
			low++;
			if(low > high) {
				break;
			}
			for(int i = low; i <= high; ++i) {
				ans.push_back(matrix[i][right]);
			}
			right--;
			if(left > right) {
				break;
			}
			for(int i = right; i >= left; --i) {
				ans.push_back(matrix[high][i]);
			}
			high--;
			if(low > high) {
				break;
			}
			for(int i = high; i >= low; --i) {
				ans.push_back(matrix[i][left]);
			}
			left++;
		}
		return ans;
    }
};