class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
		int cur = 0;
		while(s[i] != '\0') {
			cur = 0;
			while(s[i] != '\0' && s[i] != ' ') {
				cur++;
				i++;
			}
			if(s[i] == '\0') {
				break;
			}
			while(s[i] != '\0' && s[i] == ' ') {
				i++;
			}
		}
		return cur;
    }
};