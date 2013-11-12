class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
		if(digits.size() == 0)
			return ans;
		int carry = 1;
		for(int i = digits.size() - 1; i >= 0; --i) {
			int cur = digits[i] + carry;
			ans.push_back(cur % 10);
			carry = cur/10;
		}
		if(carry > 0) {
			ans.push_back(carry);
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};