class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int gap = 0;
		int n = prices.size();
		if(n < 2) {
			return gap;
		}
		int begin = 0;
		int i = 1;
		while(i < n) {
			while(i < n && prices[i] >= prices[i - 1]) {
				++i;
			}
			if(prices[i - 1] - prices[begin] > gap) {
				gap = prices[i - 1] - prices[begin];
			}
			if(i < n && prices[i] < prices[begin]) {
				begin = i;
			}
			++i;
		}
		return gap;
    }
};