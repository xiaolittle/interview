#include <stdio.h>
#include <string.h>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *begin = haystack;
		char *q = needle;
		if(*q == 0) {
			return begin;
		}
		long long hash = 0;
		long long mul = 1;
		while(true) {
			hash *= 29;
			hash += *q - 'a';
			q++;
			if(*q == 0) {
				break;
			}
			mul *= 29;
		}
		printf("%d,%d\n",'i' - 'a', 's' - 'a');
		printf("%lld, %lld\n",mul, hash);

		char *end = haystack;
		long long cur = 0;
		while(*end != 0 && (end - begin) != (q - needle)) {
			cur *= 29;
			cur += *end - 'a';
			end++;
		}
		printf("%lld\n",cur);
		if((end - begin) != (q - needle)) {
			return NULL;
		}
		if(cur == hash) {
			return begin;
		}
		printf("haha = %d\n",end - begin);
		while(*end != 0) {
			cur -= (*begin - 'a') * mul;
			cur *= 29;
			cur += *end - 'a';
			++begin;
			++end;
			if(cur == hash) {
				return begin;
			}
			printf("heihei = %lld, %lld\n",cur,mul);
		}
		return NULL;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	s.strStr("mississippi","issi");
	return 0;
}