class Solution {
public:
    void getCut(string s, vector&lt;vector&lt;string&gt; &gt; &amp;ans, vector&lt;vector&lt;bool&gt; &gt; &amp;isPalin, vector&lt;string&gt; cur, int begin) {
        if(begin &gt;= s.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(int i = begin; i &lt; s.size(); ++i) {
            if(isPalin[begin][i]) {
                cur.push_back(s.substr(begin, i + 1 - begin));
                getCut(s, ans, isPalin, cur, i + 1);
                cur.pop_back();
            }
        }
    }
    
    vector&lt;vector&lt;string&gt;&gt; partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        vector&lt;vector&lt;string&gt; &gt; ans;
        if(n &lt; 1) {
            return ans;
        }
        vector&lt;vector&lt;bool&gt; &gt; isPalin(n, vector&lt;bool&gt; (n, false));
        
        for(int i = 0; i &lt; n; ++i) {
            isPalin[i][i] = true;
        }
        for(int len = 1; len &lt; n; ++len) {
            for(int i = 0; i + len &lt; n; ++i) {
                if(len == 1) {
                    isPalin[i][i + len] = (s[i] == s[i + len]);
                } else {
                    isPalin[i][i + len] = (s[i] == s[i + len]) &amp;&amp; isPalin[i + 1][i + len - 1];
                }
            }
        }
        vector&lt;string&gt; cur;
        getCut(s, ans, isPalin, cur, 0);
        return ans;
    }
};