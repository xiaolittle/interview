#include <stdio.h>
#include <vector>

using namespace std;

int calcCoins(int k) {
    vector<int> w = {2,3,7};
    int n = w.size();
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i - w[j] >= 0) {
                dp[i] += dp[i - w[j]];
            }
        }
    }

    vector<int> combinations(k + 1, 0);
    combinations[0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = w[i]; j <= k; ++j) {
            combinations[j] += combinations[j - w[i]];
        }
    }
    printf("com = %d\n",combinations[k]);
    return dp[k];
}

int main() {
    while(true) {
        int k;
        scanf("%d",&k);
        printf("%d\n",calcCoins(k));
    }
    return 0;
}
