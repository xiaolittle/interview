#include <stdio.h>

int kinds[4] = {25, 10, 5, 1};

int calc(int cur) {
	return 1;
}

int makeChanges(int n) {
	int cur = n;
	int ways = 0;
	for(int i = 0; i * kinds[0] <= n; ++i) {
		cur -= i * kinds[0];
		for(int j = 0; j * kinds[1] <= cur; ++j) {
			cur -= j * kinds[1];
			for(int k = 0; k * kinds[2] <= cur; ++k) {
				cur -= k * kinds[2];
				ways += calc(cur);
				cur += k * kinds[2];
			}
			cur += j * kinds[1];
		}
		cur += i * kinds[0];
	}
	return ways;
}

int main(int argc, char *argv[])
{
	int ans = makeChanges(25);
	printf("ans = %d\n",ans);
	
	return 0;
}
