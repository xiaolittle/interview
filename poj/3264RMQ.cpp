#include <stdio.h>
#include <algorithm>

using namespace std;

int mini[17][50009];
int maxi[17][50009];
int num[50009];

int two[17] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

int main(int argc, char *argv[])
{
	int n,q;
	scanf("%d%d",&n,&q);

	for(int i = 0; i < n; ++i) {
		scanf("%d",&num[i]);
	}
	for(int i = 0; i < 17; ++i) {
		if(two[i] > n) {
			break;
		}
		for(int j = 0; j < n; ++j) {
			if(i == 0) {
				mini[i][j] = num[j];
				maxi[i][j] = num[j];
				//printf("mini[%d][%d] = %d\n",j, i, mini[j][i]);
			} else {
				if(j + two[i] <= n) {
					mini[i][j] = min(mini[i - 1][j], mini[i - 1][j + two[i - 1]]);
					maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][j + two[i - 1]]);
					//printf("else mini[%d][%d] = %d, maxi[%d][%d] = %d\n",j, i, mini[j][i], j, i, maxi[j][i]);
				}
			}
		}
	}

	for(int i = 0; i < q; ++i) {
		int begin,end;
		scanf("%d%d",&begin,&end);
		begin--;
		end--;
		int gap = end - begin;
		if(gap == 0) {
			printf("%d\n",0);
			continue;
		}
		int pos = 0;
		for(; pos < 17; ++pos) {
			if(two[pos] > gap) {
				break;
			}
		}
		pos--;
		//printf("pos = %d\n",pos);
		int gapmin = min(mini[pos][begin], mini[pos][end + 1- two[pos]]);
		int gapmax = max(maxi[pos][begin], maxi[pos][end + 1- two[pos]]);
		//printf("min1 = %d, min2 = %d\n",mini[begin][pos],mini[end + 1 - two[pos]][pos]);
		//printf("max1 = %d, max2 = %d\n",maxi[begin][pos],maxi[end +1 - two[pos]][pos]);
		//printf("gapmax = %d, gapmin = %d\n",gapmax,gapmin);
		printf("%d\n",gapmax - gapmin);
	}
	return 0;
}
/*
6 3
1
7
3
4
2
5
1 5
4 6
2 2
*/