class Solution {
public:
    string convert(const vector&lt;string&gt;&amp; solution) {
        string res;
        for (int i = 0; i &lt; solution.size(); ++i) {
            if (i &gt; 0) res += &#39; &#39;;
            res += solution[i];
        }
        return res;
    }
    void dfs(vector&lt;string&gt;&amp; solution, const string&amp; s, vector&lt;string &gt;&amp; res, const vector&lt;vector&lt;int&gt; &gt;&amp; next, int index) {
        if (index == s.length()) {
            res.push_back(convert(solution));
            return;
        }   
        for (int i = 0; i &lt; next[index].size(); ++i) {
            int end = next[index][i];
            solution.push_back(s.substr(index, end - index));
            dfs(solution, s, res, next, end);
            solution.pop_back();
        }
    }
    vector&lt;string&gt; wordBreak(string s, unordered_set&lt;string&gt; &amp;dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        if(n == 0) {
            return vector&lt;string&gt;();
        }
    
        vector&lt;bool&gt; dp(n + 1, false);
        dp[n] = true;
        vector&lt;vector&lt;int&gt; &gt; next(n);
        for(int i = n - 1; i &gt;= 0; --i) {
           // if(dict.count(s.substr(i))) {
        //        dp[i] = true;
          //      continue;
        //    }
            for(int len = 1; i + len &lt;= n; ++len) {
                if(dict.count(s.substr(i, len)) &amp;&amp; dp[i + len]) {
                    next[i].push_back(i + len);
                    dp[i] = true;
                    //break;
                }
            }
        }
        vector&lt;string&gt; solution;
        vector&lt;string&gt; res;
        dfs(solution, s, res, next, 0);
        return res;
        //return dp[0];
        //wordBreak(s, dict, visit, 0, n - 1);
    
        
    }
};