#include <stdio.h>
#include <vector>

using namespace std;

void dfs(vector<bool> &visit, vector<vector<int> > &path,
    int &n, int depth, vector<int> cur) {
    if(depth >= (n - 1)) {
        cur.push_back(depth);
        if(depth == (n - 1)) {
            path.push_back(cur);
        }
        return;
    }
//    if(visit[depth]) {
//        return;
//    }
    cur.push_back(depth);
    dfs(visit, path, n, depth + 1, cur);
    dfs(visit, path, n, depth + 2, cur);
    visit[depth] = true;
}

int main() {
    int n;
    scanf("%d",&n);
    vector<bool> visit(n, false);
    vector<vector<int> > path;
    vector<int> cur;
    dfs(visit, path, n, 0, cur);
    dfs(visit, path, n, 1, cur);
    for(int i = 0; i < path.size(); ++i) {
        for(int j = 0; j < path[i].size(); ++j) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}
