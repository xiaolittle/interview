class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
//        vector<int> dp(n);
//		dp[0] = 1;
//		dp[1] = 2;
//		if(n == 0) {
//			return 0;
//		}
//		for(int i = 2; i < n; ++i) {
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//		return dp[n - 1];

		int first,second,cur;
		first = 1;
		second = 2;
		if(n == 0) {
			return 0;
		} else if(n == 1) {
			return first;
		} else if(n == 2) {
			return second;
		}
		for(int i = 2; i < n; ++i) {
			cur = first + second;
			first = second;
			second = cur;
		}
		return cur;
    }
};