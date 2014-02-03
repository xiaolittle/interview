#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool validNum(string sub) {
        if(sub.size() == 0 || sub.size() > 3) {
            return false;
        }
        if(sub.size() > 1 && sub[0] == '0') {
            return false;
        }
        int tmp = 0;
        for(int i = 0; i < sub.size(); ++i) {
            tmp *= 10;
            tmp += sub[i] - '0';
        }
        if(tmp > 255) {
            return false;
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if(n < 4) {
            return ans;
        }
        for(int i = 0; i < 3; ++i) {
            if(!validNum(s.substr(0, i + 1))) {
                printf("i = %d\n",i);
                break;
            }
            for(int j = 0; j < 3 && (i + j + 2) < n; ++j) {
                if(!validNum(s.substr(i + 1, j + 1))) {
                    printf("i = %d,j = %d\n",i,j);
                    break;
                }
                for(int k = 0; k < 3 && (i + j + k + 3) < n; ++k) {
                    if(!validNum(s.substr(i + j + 2, k + 1))  || !validNum(s.substr(i + j + k + 3))) {
                        printf("i = %d,j = %d, k = %d\n", i,j,k);
                        break;
                    }
                    string cur = s.substr(0, i + 1);
                    cur += '.';
                    cur += s.substr(i + 1, j + 1);
                    cur += '.';
                    cur += s.substr(i + j + 2, k + 1);
                    cur += '.';
                    cur += s.substr(i + j + k + 3);
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.restoreIpAddresses("101023");
}
