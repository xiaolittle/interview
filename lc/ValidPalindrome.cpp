class Solution {
public:
	bool isAlp(char ch) {
		if((ch >= 'a' && ch <= 'z') || 
				(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9')) {
			return true;
		}
		return false;
	}

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
		if(n == 0) {
			return true;
		}
		int left = 0; 
		int right = n - 1;
		while(left <= right) {
			if(isAlp(s[left]) && isAlp(s[right])) {
				if(s[left] != s[right] && 
					(s[left] - 'a') != (s[right] - 'A') &&
					(s[left] - 'A') != (s[right] - 'a')) {
					return false;
				}
				++left;
				--right;
			} else if(!isAlp(s[left])) {
				++left;
			} else if(!isAlp(s[right])) {
				--right;
			}
		}
		return true;
    }
};