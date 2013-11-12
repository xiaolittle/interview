class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lena = a.size();
    	int lenb = b.size();
		if(lena == 0) {
			return b;
		} else if(lenb == 0) {
			return a;
		}
		int carry = 0;
		int i = lena - 1;
		int j = lenb - 1;
        int cur;
		string ans;
		while(i >= 0 && j >= 0) {
			int sum = a[i] - '0' + b[j] - '0' + carry;
			cur = sum % 2;
			ans = (char)(cur + '0') + ans;
			carry = sum / 2;
			--i;
			--j;
		}
		while(i >= 0) {
			int sum = a[i] - '0' + carry;
			cur = sum % 2;
			ans = (char)(cur + '0') + ans;
			carry = sum / 2;
			--i;
		}
		while(j >= 0) {
			int sum = b[j] - '0' + carry;
			cur = sum % 2;
			ans = (char)(cur + '0') + ans;
			carry = sum / 2;
			--j;
		}
		if(carry) {
			ans = (char)(carry + '0') + ans;
		}

		return ans;
    }
};