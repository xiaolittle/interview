class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *p = haystack;
		char *last = haystack;
		char *q = needle;
		if(*p == *q && *p == 0) {
			return p;
		}
		while(*p != 0) {
			while(*p && *q && *p == *q) {
				p++;
				q++;
			}
			if(*q == 0) {
				return last;
			}
			p = last + 1;
			last++;
			q = needle;
		}
		return NULL;
    }
};