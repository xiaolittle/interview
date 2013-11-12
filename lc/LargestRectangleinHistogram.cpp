class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = height.size();
        vector<int> left(n);
		vector<int> right(n);
		if(n <= 0) {
			return 0;
		}
		stack<int> st;
		for(int i = 0; i < n; ++i) {
			while(!st.empty() && height[st.top()] >= height[i]) {
				st.pop();
			}
			if(st.empty()) {
				left[i] = 0;
			} else {
				left[i] = st.top() + 1;
			}
			st.push(i);
		}

		int maxi = 0;
		st = stack<int>();
		for(int i = n - 1; i >= 0; --i) {
			while(!st.empty() && height[st.top()] >= height[i]) {
				st.pop();
			}
			if(st.empty()) {
				right[i] = n - 1;
			} else {
				right[i] = st.top() - 1;
			}
			st.push(i);
			maxi = max(maxi, (right[i] - left[i] + 1) * height[i]);
		}

		return maxi;
    }
};