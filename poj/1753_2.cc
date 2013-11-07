#include <stdio.h>
#include <algorithm>

using namespace std;

int mat[5];
int tmp[5];

int change(int curRow) {
    if(curRow != 4) {
        mat[curRow + 1] ^= mat[curRow - 1];
    }
    int steps = 0;
    for(int col = 0; col < 4; ++col) {
        if(mat[curRow - 1] & (1 << col)) {
            mat[curRow] ^= (1 << col);
            if(col > 0) {
                mat[curRow] ^= (1 << (col - 1));
            }
            if(col < 3) {
                mat[curRow] ^= (1 << (col + 1));
            }
            ++steps;
        }
    }
    return steps;
}

int main() {
    //int mat[4][4];
    char tmpch[4][4];
    for(int i = 0; i < 4; ++i) {
        scanf("%s",tmpch[i]);
        for(int j = 0; j < 4; ++j) {
            if(tmpch[i][j] == 'b') {
                tmp[i + 1] |= (1 << j);
            }
        }
    }
    int ans = 1000;
    for(int status = 0; status < ( 1 << 4); ++status) {
        memcpy(mat, tmp, sizeof(tmp));
        mat[0] = status;
        int steps = 0;
        for(int row = 0; row < 4; ++row) {
            steps += change(row + 1);
        }
        if(mat[4] == 0) {
            ans = min(ans, steps);
        }
    }
    memset(tmp, 0, sizeof(tmp));
    memset(mat, 0, sizeof(mat));
 
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(tmpch[i][j] != 'b') {
                tmp[i + 1] |= (1 << j);
            }
        }
    }

    for(int status = 0; status < ( 1 << 4); ++status) {
        memcpy(mat, tmp, sizeof(tmp));
        mat[0] = status;
        int steps = 0;
        for(int row = 0; row < 4; ++row) {
            steps += change(row + 1);
        }
        if(mat[4] == 0) {
            ans = min(ans, steps);
        }
    }
    if(ans == 1000) {
        printf("Impossible\n");
    } else {
        printf("%d\n",ans);
    }
    return 0;
}
