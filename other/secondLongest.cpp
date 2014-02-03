#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int findSecondLongest(vector<string> strs) {
    int n = strs.size();
    if(n < 2) {
        return -1;
    }
    int first,second;
    if(strs[0].size() > strs[1].size()) {
        first = 0;
        second = 1;
    } else {
        first = 1;
        second = 0;
    }
    for(int i = 2; i < n; ++i) {
        if(strs[i].size() >= strs[first].size()) {
            second = first;
            first = i;
        } else if(strs[i].size() > strs[second].size()) {
            second = i;
        }
    }
    return second;
}

int main() {
    vector<string> strs = {"12345","12345","12345","1234"};
    printf("%d\n",findSecondLongest(strs));
}
