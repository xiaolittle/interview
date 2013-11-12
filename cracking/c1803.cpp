#include <stdio.h>
#include <stdlib.h>

void randomSubset(const int &m,const int &n) {
	int a[n];
	for(int i = 0; i < n; ++i) {
		a[i] = i;
	}
	int b[m];
	for(int i = 0; i < m; ++i) {
		int cur = (rand() % (n - i)) + i;
		b[i] = a[cur];
		//int tmp = a[cur];
		a[cur] = a[i];
		//a[i] = tmp;
	}

	for(int i = 0; i < m; ++i) {
		printf("%d ", b[i]);
	}
}

int main(int argc, char *argv[])
{	
	int i = 0;
	while(i < 100) {
		randomSubset(5, 10);
		++i;
		printf("\n");
	}
	
	return 0;
}
