#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

using namespace std;

void calMolecularFormula(string s) {
    stack<int> mul;
    unordered_map<char, int> ha;
    int n = s.size();
    int i = n - 1;
    while(i >= 0) {
        if(s[i] == '(') {
            mul.pop();
        } else if(s[i] == ')') {
        } else if(s[i] >= '0' && s[i] <= '9') {
            mul.push(s[i] - '0');
        } else {
            int cur = mul.top();
            mul.pop();
            cur *= mul.top();
            if(ha.count(s[i]) > 0) {
                ha[s[i]] += cur;
            } else {
                ha[s[i]] = cur;
            }
        }
        --i;
    }
    printf("%d\n",ha.size());
}

int main() {
    string str = "C5(H2O1C)5";
    calMolecularFormula(s);
}
