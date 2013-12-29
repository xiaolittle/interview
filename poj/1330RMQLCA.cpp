#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 10009;
int n,tot;
int indegree[MAXN];
vector<vector<int> > g; 
bool visit[MAXN];
int depth[MAXN * 2],path[MAXN * 2],first[MAXN * 2];
int mini[20][MAXN];

void dfs(int root, int dep) {
	visit[root] = true;
	first[root] = tot;
	path[tot] = root;
	depth[tot++] = dep;

	for(int i = 0; i < g[root].size(); ++i) {
		if(!visit[g[root][i]]) {
			dfs(g[root][i], dep + 1);
			path[tot] = root;
			depth[tot++] = dep;
		}
	}
}

void buildRMQ() {
	for(int i = 0 ; (1 << i) <= tot; ++i) {
		for(int j = 0; j + (1 << i) <= tot; ++j) {
			if(i == 0) {
				mini[i][j] = j;
			} else {
				if(depth[mini[i - 1][j]] < depth[mini[i - 1][j + (1 << (i - 1))]]) {
					mini[i][j] = mini[i - 1][j];
				} else {
					mini[i][j] = mini[i - 1][j + (1 << (i - 1))];
				}
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

int getRMQ(int begin, int end) {
	int gap = end - begin;
	int pos = 0;
	while(true) {
		if((1<<pos) > gap) {
			break;
		}
		pos++;
	}
	--pos;
	if(depth[mini[pos][begin]] < depth[mini[pos][end - (1 << pos) + 1]]) {
		return path[mini[pos][begin]];
	} else {
		return path[mini[pos][end - (1 << pos) + 1]];
	}
}

int main(int argc, char *argv[])
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--) {
		scanf("%d",&n);
		
		memset(indegree, 0, sizeof(indegree));
		g = vector<vector<int> > (n);
		for(int i = 0; i < n - 1; ++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			--u;
			--v;
			g[u].push_back(v);
			indegree[v]++;
		}
		int begin,end;
		scanf("%d%d",&begin,&end);
		if(begin == end) {
			printf("%d\n",begin);
			continue;
		}

		int root;
		for(root = 0; root < n; ++root) {
			if(indegree[root] == 0)
				break;
		}
		solve(root);

		//begin != end;
		--begin;
		--end;
		int ans;
		if(first[begin] < first[end]) {
			ans = getRMQ(first[begin], first[end]);
		} else {
			ans = getRMQ(first[end], first[begin]);
		}
		printf("%d\n", ans + 1);
	}
	
	return 0;
}
