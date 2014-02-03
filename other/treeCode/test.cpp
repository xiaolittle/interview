#include <iostream>
using namespace std;

int solution(int A, int B) {
    int aRadix = 1;
    int bRadix = 1;
    while (aRadix * 10 <= A) {
        aRadix *= 10;
    }
    while (bRadix * 10 <= B) {
        bRadix *= 10;
    }
    bool flag = true;
    long long ans = 0;
    
    while (aRadix || bRadix) {
        if (aRadix == 0 || (!flag && bRadix > 0)) {
            ans = ans * 10 + B / bRadix % 10;
            bRadix /= 10;
        } else {
            ans = ans * 10 + A / aRadix % 10;
            aRadix /= 10;
        }
        flag = !flag;
        if (ans > 100000000) {
            return -1;
        }
    }
    return static_cast<int>(ans);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
       cout << solution(a, b) << endl;
    }
    return 0;
}

       
