#include <stdio.h>
#include <string.h>

const int MAXN = 924;

int g[MAXN][MAXN];
int indegree[MAXN];
int len[MAXN],ans[MAXN];
int tot, n;
bool visit[MAXN];
int path[MAXN*2],depth[MAXN*2],first[MAXN*2];
int mini[17][MAXN*2];

void dfs(int root, int dep) {
	visit[root] = true;
	first[root] = tot;
	path[tot] = root;
	depth[tot++] = dep;
	for(int i = 0; i < len[root]; ++i) {
		if(!visit[g[root][i]]) {
			dfs(g[root][i], dep + 1);
			path[tot] = root;
			depth[tot++] = dep;
		}
	}
}

void buildRMQ() {
	int i,j;
	for(i = 0; (1 << i) <= tot; ++i) {
		for(j = 0; j + (1 << i) <= tot; ++j) {
			if(i == 0) {
				mini[i][j] = j;
				//printf("mini[%d][%d] = %d\n",j, i, mini[j][i]);
			} else {
				if(depth[mini[i - 1][j]] < depth[mini[i - 1][j + (1<<(i - 1))]]) {
					mini[i][j] = mini[i - 1][j];
				} else {
					mini[i][j] = mini[i - 1][j + (1 << (i - 1))];
				}
				//mini[i][j] = min(mini[i - 1][j], mini[i - 1][j + 1 << (i - 1)]);
					//maxi[i][j] = max(maxi[i - 1][j], maxi[i - 1][j + two[i - 1]]);
					//printf("else mini[%d][%d] = %d, maxi[%d][%d] = %d\n",j, i, mini[j][i], j, i, maxi[j][i]);
			}
		}
	}
}

void solve(int root) {
	tot = 0;
	memset(visit, false, sizeof(visit));
	dfs(root, 0);
	buildRMQ();
}

int RMQ(int begin, int end) {
	int pos = 0;
	int gap = end - begin;
	while(true) {
		if((1<<pos) > gap) {
			break;
		}
		pos++;
	}
	pos--;
	if(depth[mini[pos][begin]] < depth[mini[pos][end + 1 - (1<<pos)]]) {
		return path[mini[pos][begin]];
	} else {
		return path[mini[pos][end + 1 - (1<<pos)]];
	}
}

int LCA(int begin, int end) {
	if(first[begin] < first[end]) {
		return RMQ(first[begin], first[end]);
	} else {
		return RMQ(first[end],first[begin]);
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(len,0,sizeof(len));
		memset(indegree,0,sizeof(indegree));
		memset(ans,0,sizeof(ans));
		for(int i = 0; i < n; ++i) {
			int node,edge;
			scanf("%d",&node);
			node--;
			scanf(" : ( %d )",&edge);
			for(int i = 0; i < edge; ++i) {
				int tmp;
				scanf("%d",&tmp);
				g[node][len[node]++] = tmp - 1;
				//g[tmp - 1][len[tmp - 1]++] = node;
				indegree[tmp - 1]++;
			}
		}
		int root = 0;
		for(; root < n; ++root) {
			if(indegree[root] == 0)
				break;
		}
		solve(root);

		int q;
		scanf("%d",&q);
		//printf("hahahahha\n");
		for(int i = 0; i < q; ++i) {
			int u,v;
			scanf(" ( %d %d )", &u, &v);
			ans[LCA(u - 1, v - 1)]++;
			//printf("%d,u = %d,v = %d\n",i,u,v);
		}
		for(int i = 0; i < n; ++i) {
			if(ans[i] > 0) {
				printf("%d:%d\n",i + 1,ans[i]);
			}
		}

	}
	
	return 0;
}
