class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num1.size();
		int n = num2.size();
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		vector<int> res(n + m, 0);

		for(int i = 0; i < m; ++i) {
			int carry = 0;
			for(int j = 0; carry || j < n; ++j) {
				if(j < n) {
					carry += (num1[i] - '0') * (num2[j] - '0');
				}
				carry += res[i + j];
				res[i + j] = carry % 10;
				carry /= 10;
			}
		}

		string str;
		int cur = n + m - 1;
		while(cur > 0 && res[cur] == 0) {
			--cur;
		}

		while(cur >= 0) {
			str += static_cast<char>(res[cur] + '0');
			--cur;
		}
		return str;
    }
};