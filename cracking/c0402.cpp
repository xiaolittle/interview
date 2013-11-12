#include <stdio.h>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Node
{
	int id;
	vector<int> adj;
};

int g[109][109];

bool hasRoute(int u, int v, vector<Node> graph) {
	set<int> visited;
	queue<int> q;
	visited.insert(u);
	q.push(u);

	printf("u = %d,v = %d\n",u, v);
	while(!q.empty()) {
		Node begin = graph[q.front()];
		q.pop();
		for(int i = 0; i < begin.adj.size(); ++i) {
			int cur = begin.adj[i];
			if(cur == v) {
				return true;
			}
			if(!visited.count(cur)) {
				q.push(cur);
			}
		}
		visited.insert(begin.id);
	}
	return false;
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	vector<Node> graph;
	for(int i = 0; i < n; ++i) {
		Node cur;
		cur.id = i;
		vector<int> tmp; 
		for(int j = 0; j < n; ++j) {
			scanf("%d",&g[i][j]);
			if(g[i][j] == 1) {
				tmp.push_back(j);
			}
		}
		cur.adj = tmp;
		graph.push_back(cur);
	}
	int u,v;
	printf("input begin = \n");
	scanf("%d",&u);
	printf("input end = \n");
	scanf("%d",&v);
	bool has = hasRoute(u, v, graph);
	printf("Flag is %d\n",has);
	
	return 0;
}

/*
2
0 1
1 0
0
1

3
0 1 0
1 0 0
1 0 0
0
2

3
0 1 0
1 0 0
1 0 0
2
0
*/
