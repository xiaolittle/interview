#include <stdio.h>

int findDiffBit(int a, int b) {
	int count = 0;
	for(int c = a^b; c > 0; c >>= 1) {
		count += c & 1;
	}
	return count;
}

int main(int argc, char *argv[])
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans = findDiffBit(a, b);
	printf("%d\n",ans);
	
	return 0;
}
