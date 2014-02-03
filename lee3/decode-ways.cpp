#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n <= 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            if(s[i - 1] != '0') {
                dp[i] += dp[i - 1];
                printf("i = %d,%d\n",i, dp[i]);
            }
            int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(val == 0 || (dp[i - 1] == '0' && dp[i - 2] > '3')) {
                return 0;
            }
            if(s[i - 2] != '0' && val <= 26) {
                printf("%d\n",dp[i]);
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    s.numDecodings("101");
    return 0;
}
