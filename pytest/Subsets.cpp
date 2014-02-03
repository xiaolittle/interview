class Solution {
public:
    void getSubsets(vector&lt;int&gt; &amp;S, vector&lt;vector&lt;int&gt; &gt; &amp;ans, vector&lt;int&gt; &amp;cur, int dep) {
        ans.push_back(cur);
        if(dep &gt;= S.size()) {
            return;
        }
        for(int i = dep; i &lt; S.size(); ++i) {
            cur.push_back(S[i]);
            getSubsets(S, ans, cur, i + 1);
            cur.pop_back();
        }
    }
    vector&lt;vector&lt;int&gt; &gt; subsets(vector&lt;int&gt; &amp;S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector&lt;vector&lt;int&gt; &gt; ans;
        vector&lt;int&gt; cur;
        getSubsets(S, ans, cur, 0);
        return ans;
    }
};