#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
   vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int begin = 0, len = 0, n = words.size(), i;
        for(i = 0; i < n; ++i) {
            if((len + words[i].size() + i - begin) > L) {
                printf("hah i = %d\n",i);
                ret.push_back(connect(words, begin, i - 1, len, L, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        ret.push_back(connect(words, begin, n - 1, len, L, true));
        return ret;
    }
    
    string connect(const vector<string> &words, int begin, int end, int len,const int &L, bool left) {
        string cur;
        int n = end - begin;
        for(int i = begin; i <= end; ++i) {
            cur += words[i];
            printf("iiiii\n");
            addSpace(cur, i, L - len, n, left);
        }
        if(cur.size() < L) {
            cur.append(L - cur.size(), ' ');
        }
        return cur;
    }
    
    void addSpace(string &s, int i, int L, int n, bool left) {
        if(L < 1) {
            return;
        }
        printf("eeeeeeeee, L = %d,n = %d,i = %d\n",L, n, i);
        int ct = left? 1:(L/n + (i < (L%n) ? 1:0));
        s.append(ct, ' ');
    }
};

int main() {
    vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    Solution s;
    s.fullJustify(words, 6);
}
