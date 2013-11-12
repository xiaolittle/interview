class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
		int n = prices.size();
		if(n < 2) {
			return cur;
		}
		int cur = 0;
		int i = 1;
		while(i < n) {
			while(i < n && prices[i] >= prices[i - 1]) {
				++i;
			}
			if(prices[i - 1] - prices[cur] > 0) {
				sum += prices[i - 1] - prices[cur];
			}
			cur = i;
			++i;
		}
		return sum;
    }
};