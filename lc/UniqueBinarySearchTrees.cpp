class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> f(n + 1);
		f[0] = 1;
		f[1] = 1;
		for(int i = 2; i <= n; ++i) {
			int cur = 0;
			for(int j = 0; j < i; ++j) {
				cur += f[j] * f[i - j - 1];
			}
			f[i] = cur;
		}
		return f[n];
    }
};