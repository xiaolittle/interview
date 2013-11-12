class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		while(*str != 0 && *str == ' ') {
			str++;
		}
		if(*str == 0) {
			return 0;
		}
		int flag = 0;
		if(*str == '-') {
			flag = 1;
			++str;
		} else if(*str == '+') {
			++str;
		}
        unsigned int ans = 0;
		unsigned int maxInt = numeric_limits<int>::max();
		while(*str != 0) {
			if(*str < '0' || *str > '9') {
				break;
			}
			int cur = *str- '0';
			if(ans > ((maxInt + flag - cur ) / 10)) {
				return flag ? numeric_limits<int>::min() : numeric_limits<int>::max();
			}
			ans *= 10;
			ans += cur;
			++str;
		}
		return flag ? (-1*ans) : ans;
    }
};