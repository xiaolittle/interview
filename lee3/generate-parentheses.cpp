#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    void getAns(int left, int right, int n, string cur, vector<string> &ans) {
        if(left > n || right > n || right > left) {
            return;
        }
        if(left == n && right == n) {
            ans.push_back(cur);
            return;
        }
        if(left < n) {
            cur += '(';
            getAns(left + 1, right, n, cur, ans);
            cur.erase(cur.size() - 1, 1);
        }
        if(left > right) {
            cur += ')';
            getAns(left, right + 1, n, cur, ans);
            //cur.erase(cur.size() - 1, 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        int left = 0;
        int right = 0;
        getAns(left, right, n, cur, ans);
        for(int i = 0; i < ans.size(); ++i) {
            printf("%s\n",ans[i].c_str());
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.generateParenthesis(3);
}
