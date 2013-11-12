class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
		int l,r;
		int max = 0;
		string ans = "";
		for(int i = 0; i < len; ++i) {
			l = i;
			r = i;
			while(l >= 0 && r < n && s[l] == s[r]) {
				--l;
				++r;
			}
			++l;
			--r;
			if(r + 1 - l > max) {
				max = r + 1 - l;
				ans = s.substr(l, max);
			}
			l = i;
			r = i + 1;
			while(l >= 0 && r < n && s[l] == s[r]) {
				--l;
				++r;
			}
			++l;
			--r;
			if(r + 1 - l > max) {
				max = r + 1 - l;
				ans = s.substr(l, max);
			}
		}
		return ans;
    }
};