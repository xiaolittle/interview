#include <stdio.h>
#include <iostream>

using namespace std;

int zipcode(int a, int b) {
    int aZip = 1;
    int bZip = 1;
    bool flag = true;
    while(aZip*10 <= a) {
        aZip *= 10;
    }
    while(bZip*10 <= b) {
        bZip *= 10;
    }
    long long ans = 0;
    while(aZip || bZip) {
        if(!aZip || (!flag && bZip)) {
            //ans *= 10;
            ans = ans * 10 + b / bZip % 10;
            //ans += b/bZip;
            //b = b % bZip;
            bZip /= 10;
            printf("bZip = %d, ans = %d\n",bZip, ans);
        } else {
            //ans *= 10;
            //ans += a / aZip;
            //a = a % aZip;
            ans = ans * 10 + a / aZip % 10;
            aZip /= 10;
            printf("aZip = %d, ans = %d\n",aZip, ans);
        }
        flag = !flag;
        if(ans > 10000000) {
            return -1;
        }
    }
    return static_cast<int>(ans);
}

int main() {
    int a,b;
    while(cin >> a >> b) {
        int ans = zipcode(a, b);
        cout << ans << endl;
    }
}
