#include <stdio.h>
#include <string.h>

using namespace std;

int anc[10009];
int visit[10009];

int main(int argc, char *argv[])
{
	int size;
	scanf("%d",&size);
	while(size--) {
		memset(visit,0,sizeof(visit));
        memset(anc,0,sizeof(anc));
		int x,y;
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n - 1; ++i) {
			scanf("%d%d",&x,&y);
			anc[y] = x;
		}
		scanf("%d%d",&x,&y);
		while(x) {
			visit[x] = 1;
			x = anc[x];
		}
		while(y) {
			if(visit[y]) {
				break;
			}
			y = anc[y];
		}
		printf("%d\n",y);
	}
	
	return 0;
}
