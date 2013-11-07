#include <stdio.h>
#include <algorithm>

using namespace std;

void change(int mat[][4], int row, int col) {
    mat[row][col] = !mat[row][col];
    if(row > 0) {
        mat[row - 1][col] = !mat[row - 1][col];
    }
    if(row < 3) {
        mat[row + 1][col] = !mat[row + 1][col];
    }
    if(col > 0) {
        mat[row][col - 1] = !mat[row][col - 1];
    }
    if(col < 3) {
        mat[row][col + 1] = !mat[row][col + 1];
    }
}

bool isValid(int mat[][4]) {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(mat[i][j] != mat[0][0]) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int mat[][4], int &ans, int depth, int steps) {
    if(depth >= 16) {
        if(isValid(mat)) {
            if(ans == -1) {
                ans = steps;
            } else {
                ans = min(steps, ans);
            }
        }
        return;
    }
    int row = depth / 4;
    int col = depth % 4;
    dfs(mat, ans, depth + 1, steps);
    change(mat, row, col);
    dfs(mat, ans, depth + 1, steps + 1);
    change(mat, row, col);
}

int main() {
    int mat[4][4];
    for(int i = 0; i < 4; ++i) {
        char tmp[10];
        scanf("%s",tmp);
        for(int j = 0; j < 4; ++j) {
            if(tmp[j] == 'b') {
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
        }
    }
    int ans = -1;
    dfs(mat, ans, 0, 0);
    if(ans == -1) {
        printf("Impossible\n");
    } else {
        printf("%d\n",ans);
    }
    return 0;
}
