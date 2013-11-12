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
        vector<bool> dp(n, false);
        for(int i = n - 1; i >= 0; --i) {
            if(dict.count(s.substr(i))) {
                dp[i] = true;
                continue;
            }
            for(int len = 1; i + len < n; ++len) {
                if(dict.count(s.substr(i, len)) && dp[i + len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
        //wordBreak(s, dict, visit, 0, n - 1);
        //return visit[0][n - 1] == 1;
    }
