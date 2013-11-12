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

		if(*(p + 1) != '*') {
			return ((*s == *p || (*p == '.' && *s != 0)) && isMatch(s + 1, p + 1));
		} else {
			if(isMatch(s, p + 2)) {
				return true;
			} else {
				while(*s != 0 && (*p == '.' ||  *s == *p)) {
					if(isMatch(s + 1, p + 2)) {
						return true;
					}
					++s;
				}
			}
		}

		return false;
    }
};