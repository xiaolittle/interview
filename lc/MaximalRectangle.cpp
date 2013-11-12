class Solution {
public:
	int getLevelAns(vector<int> &level) {
		stack<int> st;
		int len = level.size();
		vector<int> left(len);
		vector<int> right(len);

		for(int i = 0; i < len; ++i) {
			while(!st.empty() && (level[st.top()] >= level[i])) {
				st.pop();
			}
			if(st.empty()) {
				left[i] = 0;
			} else {
				left[i] = st.top() + 1;
			}
			st.push(i);
		}

		st = stack<int>();
		int ans = 0;
		for(int i = len - 1; i >= 0; --i) {
			while(!st.empty() && (level[st.top()] >= level[i])) {
				st.pop();
			}
			if(st.empty()) {
				right[i] = len - 1;
			} else {
				right[i] = st.top() - 1;
			}
			st.push(i);
			int tmp = (right[i] + 1 - left[i]) * level[i];
			if(tmp > ans) {
				ans = tmp;
			}
		}
		return ans;
	}

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = matrix.size();
		if(m == 0) {
			return 0;
		}
		int n = matrix[0].size();
		if(n == 0) {
			return 0;
		}
        vector<vector<int> > height(m, vector<int> (n));

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(matrix[i][j] == '1') {
					if(i == 0) {
						height[i][j] = 1;
					} else {
						height[i][j] = height[i - 1][j] + 1;
					}
				} else {
					height[i][j] = 0;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < m; ++i) {
			ans = max(ans, getLevelAns(height[i]));
		}
		return ans;
    }
};