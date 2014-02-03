class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        if(n &lt; 1) {
            return ans;
        }
        ans = &quot;1&quot;;
        for(int i = 1; i &lt; n; ++i) {
            string cur;
            int pos = 0;
            int len = ans.size();
            while(true) {
                char curchar = ans[pos];
                int i = pos + 1;
                while(i &lt; len &amp;&amp; ans[pos] == ans[i]) {
                    ++i;
                }
                cur += (char)(i - pos + &#39;0&#39;);
                cur += curchar;
                pos = i;
                if(pos &gt;= len) {
                    break;
                }
            }
            ans = cur;
        }
        return ans;
    }
};