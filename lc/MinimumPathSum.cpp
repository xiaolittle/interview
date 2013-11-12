class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = grid.size();
		int n = grid[0].size();
        vector<int> last(n);
		vector<int> cur(n);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == 0 && j == 0) {
					cur[j] = grid[i][j];
				} else if(i == 0) {
					cur[j] = cur[j - 1] + grid[i][j];
				} else if(j == 0){
					cur[j] = last[j] + grid[i][j];
				} else {
					cur[j] = min(last[j], cur[j - 1]) + grid[i][j];
				}
			}
			last = cur;
		}
		return cur[n - 1];
    }
};