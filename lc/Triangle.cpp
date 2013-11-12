class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = triangle.size();
		if(height < 1) {
			return 0;
		}
		int wid = triangle[height - 1].size();
		vector<int> cur(wid);
		vector<int> last(wid);
		last[0] = triangle[0][0];
		cur[0] = triangle[0][0];
		for(int i = 1; i < height; ++i) {
			for(int j = 0; j < triangle[i].size(); ++j) {
				if(j == 0) {
					cur[j] = last[j] + triangle[i][j];
				} else if(j == triangle[i].size() - 1) {
					cur[j] = last[j - 1] + triangle[i][j];
				} else {
					cur[j] = min(last[j - 1], last[j]) + triangle[i][j];
				}
			}
			last = cur;
		}
		int mini = numeric_limits<int>::max();
		for(int i = 0; i < wid; ++i) {
			if(cur[i] < mini) {
				mini = cur[i];
			}
		}
		return mini;
    }
};