class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector&lt;string&gt; strRows(nRows);
        int i = 0;
        int n = s.size();
        string ans;
        if(n == 0) {
            return ans;
        }
        while(i &lt; n) {
            for(int j = 0; j &lt; nRows &amp;&amp; i &lt; n; ++i, ++j) {
                strRows[j] += s[i];
            }
            if(i &gt;= n) {
                break;
            }
            for(int j = nRows - 2; j &gt;= 1 &amp;&amp; i &lt; n; --j, ++i) {
                strRows[j] += s[i];
            }
        }
        for(int i = 0; i &lt; nRows; ++i) {
            ans += strRows[i];
        }
        return ans;
    }
};