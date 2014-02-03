#include <string>
#include <string.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

int findFirstNoDup(string s) {
    int n = s.size();
    unordered_map<char, int> ha;
    for(int i = 0; i < n; ++i) {
        ha[s[i]]++;
    }
    int mini = n;
    for(int i = 0; i < n; ++i) {
        if(ha[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string a = "abacb";
    printf("%d\n",findFirstNoDup(a));
}
