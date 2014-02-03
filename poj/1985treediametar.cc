#include <stdio.h>
#include <vector>

using namespace std;

struct TNode {
    int t;
    int weight;
    TNode(int x, int y): t(x), weight(y) {};
};

vector<vector<TNode> > g(90000);
vector<int> dis(90000, 0);
vector<bool> visit(90000, false);

void dfs(int cur, int &ans) {
    int curmax = 0;
    if(visit[cur]) {
        return;
    }
    visit[cur] = true;
    if(g[cur].size() == 0) {
        dis[cur] = 0;
        return;
    }
    for(int i = 0; i < g[cur].size(); ++i) {
        if(!visit[g[cur][i].t]) {
            dfs(g[cur][i].t, ans);
            if((dis[g[cur][i].t] + g[cur][i].weight) + curmax > ans) {
                ans = dis[g[cur][i].t] + g[cur][i].weight + curmax;
            }
            curmax = max(curmax, dis[g[cur][i].t] + g[cur][i].weight);
        }
    }
    dis[cur] = curmax;
}

int main() {
    int m,n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        char ch[2];
        scanf("%d%d%d%s", &x, &y, &w, ch);
        --x; --y;
        g[x].push_back(TNode(y, w));
        g[y].push_back(TNode(x, w));
    }
    int ans = 0;
    int cur = 0;
    dfs(cur, ans);
    printf("%d\n",ans);
}

