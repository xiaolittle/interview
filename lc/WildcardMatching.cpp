class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0 && *p == 0) {
			return true;
		}
		if(*p == 0) {
			return *s == 0;
		}
		if(*s == 0) {
			return *p == '*' && isMatch(s, p + 1);
		}

		if(*p != '*') {
			return ((*p == '?' || *s == *p) && isMatch(s + 1, p + 1));
		} else {
			while(*s != 0) {
				if(isMatch(s + 1, p + 1) || isMatch(s, p + 1)) {
					return true;
				}
				++s;
			}
		}
		return false;
    }
};