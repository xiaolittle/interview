#include <stdio.h>

int calc(int num, int d, int pow) {
	int nextpower = pow * 10;
	int right = num % pow;
	int roundDown = num - num % nextpower;
	int roundUp = roundDown + nextpower;

	int dig = (num / pow) % 10;

	if(dig < 2) {
		return roundDown / 10;
	} else if(dig == 2) {
		return roundDown/ 10 + right + 1;
	} else {
		return roundUp / 10;
	}
}

int calcTheDigitOfNum(int num) {
	int ans = 0;
	int cur = 1;
	for(int i = 0; (num / cur) > 0; ++i) {
		ans += calc(num, i, cur);
		cur *= 10;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	while(true) {
		int num;
		scanf("%d",&num);
		printf("%d\n",calcTheDigitOfNum(num));
	}
	
	return 0;
}
