class Solution {
public:
    string convert(vector<string> &solution) {
        string tmp;
        for(int i = 0; i < solution.size(); ++i) {
            if(i > 0) {
                tmp += ' ';
            }
            tmp += solution[i];
        }
        return tmp;
    }
    void dfs(const string &s,const vector<vector<int> > &next, vector<string> &ans, int dep, vector<string> &solution) {
        if(dep == s.size()) {
            ans.push_back(convert(solution));
            return;
        }
        for(int i = 0; i < next[dep].size(); ++i) {
            solution.push_back(s.substr(dep, next[dep][i] - dep));
            dfs(s, next, ans, next[dep][i], solution);
            solution.pop_back();
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if(n == 0) {
            return vector<string> ();
        }
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        vector<vector<int> > next(n);
        for(int i = n - 1; i >= 0; --i) {
            for(int len = 1; i + len <= n; ++len) {
                if(dict.count(s.substr(i, len)) && dp[i + len]) {
                    dp[i] = true;
                    next[i].push_back(i + len);
                    //break;
                }
            }
        }
        vector<string> solution;
        vector<string> ans;
        dfs(s, next, ans, 0, solution);
        return ans;
    }
};