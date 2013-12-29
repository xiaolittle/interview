#include <stdio.h>
#include <string.h>

int a[17][309];
int row,col;
int num;
int bitfield[17][10];
int sum[17];
int tmpbit[10];

bool lineAllone(int cur) {
	for(int i = 0; i < num - 1; ++i) {
		if(bitfield[cur][i] != 0xFFFFFFFF) {
			return false;
		}
	}
	int last = col % 32;
	int mask = (1 << last) - 1;
	if(last == 0) {
		mask = ~0;
	}
	//printf("mask = %d\n",mask);
	if(bitfield[cur][num - 1] == mask) {
		return true;
	}

	return false;
}

bool allone(int cur) {
	for(int i = 0; i < num - 1; ++i) {
		if((bitfield[cur][i] | tmpbit[i]) != 0xFFFFFFFF) {
			//printf("hahahaha,cur = %d,bitfield[cur][i] = %d,tmpbit[i] = %d\n",cur,bitfield[cur][i],tmpbit[i]);
			return false;
		}
	}
	int last = col % 32;
	int mask = (1 << last) - 1;
	if(last == 0) {
		mask = ~0;
	}

	if((bitfield[cur][num - 1] | tmpbit[num - 1]) == mask) {
		return true;
	}
	//printf("555555555,bitfield[cur][num - 1] = %d,tmpbit[num - 1] = %d\n",bitfield[cur][num - 1],tmpbit[num - 1]);
	return false;
}

bool allzero(int cur) {
	for(int i = 0; i < num; ++i) {
		if((bitfield[cur][i] & tmpbit[i]) != 0) {
			return false;
		}
	}
	return true;
}

void set(int cur) {
	for(int i = 0; i < num; ++i) {
		tmpbit[i] |= bitfield[cur][i];
	}
}

void reset(int cur) {
	for(int i = 0; i < num; ++i) {
		tmpbit[i] ^= bitfield[cur][i];
	}
}

bool dfs(int dep, int total) {
	if(total == col) {
		//printf("Yes, I found it\n");
		return true;
	}
	if(dep >= row) {
		return false;
	}
//	if(dfs(dep + 1, total)) {
//		return true;
//	}
//	if(sum[dep] + total > col) {
//		return false;
//	}
//	if(!allzero(dep)) {
//		//printf("ishere,dep = %d\n",dep);
//		return false;
//	}

//	if(allone(dep)) {

	for(int i = dep; i < row; ++i) {
		if(sum[i] + total > col || !allzero(i)) {
			continue;
		}
		set(i);
		if(dfs(i + 1, total + sum[i])) {
			return true;
		}
		reset(i);
	}
	return false;
}

void calc() {
	for(int i = 0; i < row; ++i) {
//		if(lineAllone(i)) {
		if(sum[i] == col) {
			//printf("Yes, I found it\n");
			return;
		}
		for(int j = 0; j < num; ++j) {
			tmpbit[j] = bitfield[i][j];
			//printf("calc tmpbit[%d] = %d\n",j,tmpbit[j]);
		}
		if(dfs(i + 1, sum[i])) {
			return;
		}
	}
	printf("It is impossible\n");
}

int main(int argc, char *argv[])
{
	while(scanf("%d%d",&row,&col) != EOF) {
		if(row == 0 || col == 0) {
			printf("It is impossible\n");
			continue;
		}
		memset(tmpbit, 0, sizeof(tmpbit));
		memset(bitfield, 0, sizeof(bitfield));
		memset(a, 0, sizeof(a));
		memset(sum,0, sizeof(sum));
		//num = (col - 1) / 32 + 1;
		num = (col + 31) / 32;
		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				scanf("%d",&a[i][j]);
				if(a[i][j]) {
					++sum[i];
					bitfield[i][j >> 5] |= (1 << (j & 0x1F));
					//printf("bitfield[%d][%d >> 5] = %d\n",i,j,bitfield[i][j >> 5]);
				}
			}
			//printf("bitfield[%d][%d] = %d\n",i,num - 1,bitfield[i][num - 1]);
		}
		//num = (col - 1) / 32 + 1;
		//calc();
		if(dfs(0, 0)) {
			printf("Yes, I found it\n");
		} else {
			printf("It is impossible\n");
		};
	}
	
	return 0;
}

/*
3 3
0 1 1
1 1 0
0 1 0
1 32
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1
2 32
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
3 32
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1
3 31
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0
1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 33
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 33
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
5 33
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0
2 32
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1
1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
2 33
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1 1
*/
