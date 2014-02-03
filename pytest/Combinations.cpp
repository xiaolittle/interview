class Solution {
public:
    void getCombine(int n, int k, vector&lt;vector&lt;int&gt; &gt; &amp;ans, vector&lt;int&gt; cur, int dep) {
        if(cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for(int i = dep; i &lt; n; ++i) {
            cur.push_back(i + 1);
            getCombine(n, k, ans, cur, i + 1);
            cur.pop_back();
        }
    }
    vector&lt;vector&lt;int&gt; &gt; combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; ans;
        vector&lt;int&gt; cur;
        int dep = 0;
        getCombine(n, k, ans, cur, dep);
        return ans;
    }
};