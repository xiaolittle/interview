class Solution {
public:
    int wordBreak(string s, unordered_set<string> &dict, vector<vector<int> > &visit, int begin, int end) {
        if(visit[begin][end] != -1) {
            return visit[begin][end];
        }
        int n = s.size();
        if(n == 1) {
            if(dict.count(s)) {
                return visit[begin][end] = 1;
            }
            visit[begin][end] = 0;
            return visit[begin][end];
        }
        if(dict.count(s)) {
             visit[begin][end] = 1;
             return visit[begin][end];
        }
        for(int len = 1; len < n; ++len) {
            if(dict.count(s.substr(0, len)) <= 0) {
                visit[begin][begin + len - 1] = 0;
                continue;
            }
            visit[begin][begin + len - 1] = 1;
            if(wordBreak(s.substr(len), dict, visit, begin + len, end) == 1) {
                return visit[begin][end] = 1;
            }
        }
        visit[begin][end] = 0;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if(n == 0) {
            return true;
        }
        if(n == 1) {
            if(dict.count(s)) {
                return true;
            }
            return false;
        }
        if(dict.count(s)) {
            return true;
        }
        vector<vector<int> > visit(n, vector<int>(n, -1));
        wordBreak(s, dict, visit, 0, n - 1);
        return visit[0][n - 1] == 1;
    }
};