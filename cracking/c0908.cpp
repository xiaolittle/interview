#include <stdio.h>

int makeChanges(int n, int denom) {
	int next_denom = 0;
	switch(denom) {
		case 25:
			next_denom = 10;/
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			return 1;
	}

	int ways = 0;
	for(int i = 0; i * denom <= n; ++i) {
		ways += makeChanges(n - i* denom, next_denom);
	}
	return ways;
}

int main(int argc, char *argv[])
{
	int ans = makeChanges(4, 1);
	printf("ans = %d\n",ans);
	
	return 0;
}
