class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(len &lt; 2) {
            return true;
        }
        int l = 0;
        int r = len - 1;
        while(l &lt; r) {
            if(!((s[l] &gt;= &#39;a&#39; &amp;&amp; s[l] &lt;= &#39;z&#39;) || (s[l] &gt;= &#39;A&#39; &amp;&amp; s[l] &lt;= &#39;Z&#39;)
                || (s[l] &gt;= &#39;0&#39; &amp;&amp; s[l] &lt;= &#39;9&#39;))) {
                ++l;
                continue;
            }
            if(!((s[r] &gt;= &#39;a&#39; &amp;&amp; s[r] &lt;= &#39;z&#39;) || (s[r] &gt;= &#39;A&#39; &amp;&amp; s[r] &lt;= &#39;Z&#39;)
                || (s[r] &gt;= &#39;0&#39; &amp;&amp; s[r] &lt;= &#39;9&#39;))) {
                --r;
                continue;
            }
            int left,right;
            if((s[l] &gt;= &#39;0&#39; &amp;&amp; s[l] &lt;= &#39;9&#39;)|| (s[r] &gt;= &#39;0&#39; &amp;&amp; s[r] &lt;= &#39;9&#39;)) {
                if(s[l] != s[r]) {
                    return false;
                }
                ++l;
                --r;
                continue;
            }
            if(s[l] &gt;= &#39;a&#39; &amp;&amp; s[l] &lt;= &#39;z&#39;) {
                left = s[l] - &#39;a&#39;;
            } else {
                left = s[l] - &#39;A&#39;;
            }
            if(s[r] &gt;= &#39;a&#39; &amp;&amp; s[r] &lt;= &#39;z&#39;) {
                right = s[r] - &#39;a&#39;;
            } else {
                right = s[r] - &#39;A&#39;;
            }
            if(left != right) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};