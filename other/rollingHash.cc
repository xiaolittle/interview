#include <stdio.h>
#include <string>
#include <string.h>
#include <unordered_set>

using namespace std;

int calcUni(const string &s) {
    unordered_set<int> ha;
    int n = s.size();
    int base = 1;
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        cur *= 29;
        cur += s[i];
        base *= 29;
    }
    ha.insert(cur);
//    base /= 29;
    printf("cur = %d, base = %d\n",cur,base);
    for(int i = 1; i < n; ++i) {
        cur *= 29;
        cur -= s[i] * base;
        cur += s[i];
        //cur = (cur - s[i]*base)*29 + s[i];
        ha.insert(cur);
        printf("cur = %d\n",cur);
    }
    return ha.size();
}

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int ans = calcUni(s);
    printf("%d\n",ans);
}
