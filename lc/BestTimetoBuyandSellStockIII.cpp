class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = prices.size();
        vector<int> left(n, 0);
		vector<int> right(n, 0);
		if(n < 2) {
			return 0;
		}

		int i = 0; 
		int begin = 0;
		int maxi = 0;
		while(i < n) {
			if(prices[i] - prices[begin] > maxi) {
				maxi = prices[i] - prices[begin];
			}
			left[i] = maxi;
			if(prices[i] < prices[begin]) {
				begin = i;
			}
			++i;
		}
		i = n - 1;
		begin = n - 1;
		maxi = 0;
		while(i >= 0) {
			if(prices[begin] - prices[i] > maxi) {
				maxi = prices[begin] - prices[i];
			}
			right[i] = maxi;
			if(prices[i] > prices[begin]) {
				begin = i;
			}
			--i;
		}
		int ans = 0;
		for(i = 0; i < n - 1; ++i) {
			if(left[i] + right[i + 1] > ans) {
				ans = left[i] + right[i + 1];
			}
		}
		return max(max(left[n - 1], right[0]), ans);
    }
};