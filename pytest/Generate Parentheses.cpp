class Solution {
public:
    void dfs(vector&lt;string&gt; &amp;ans, string cur, int left, int right, int &amp;n) {
        if(left == n &amp;&amp; right == n) {
            ans.push_back(cur);
            return;
        }
        if(left &lt; n) {
            cur += &#39;(&#39;;
            dfs(ans, cur, left + 1, right, n);
            cur.erase(cur.size() - 1, 1);
        }
        if(left &gt; right) {
            cur += &#39;)&#39;;
            dfs(ans, cur, left, right + 1, n);
            cur.erase(cur.size() - 1, 1);
        }
    }
    vector&lt;string&gt; generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = 0;
        vector&lt;string&gt; ans;
        if(n == 0) {
            return ans;
        }
        string cur;
        dfs(ans, cur, left, right, n);
        return ans;
    }
};