#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int flag = 1;
		long long c = dividend;
		long long b = divisor;
		if(dividend < 0) {
			flag = -1 * flag;
			c = -1 * c;
		}
		if(divisor < 0) {
			flag = -1 * flag;
			b = -1 * b;
		}
        if (c < b) {
			//printf("hahaha\n");
			return 0;
		}
		if(c == b) {
			return flag;
		}
		long long cur = 1;
		long long a = b;

		long long ans = 0;

		while(true) {
			while(c >= a) {
				a <<= 1;
				cur <<= 1;
			}
			a >>= 1;
			cur >>= 1;
			//printf("c = %lld,a = %lld,cur = %lld\n",c,a,cur);
			c -= a;
			ans += cur;
			a = b;
			cur = 1;
			if(c < a) {
				break;
			}
		}
		return (flag * ans);

    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	Solution a;
	a.divide(-2147483648, 1);
	return 0;
}