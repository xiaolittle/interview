class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if(len &lt; 2) {
            return s;
        }
        int start = -1;
        int end = -1;
        for(int i = 0; i &lt; len; ++i) {
            int l = i;
            int r = i;
            while(l &gt;= 0 &amp;&amp; r &lt; len &amp;&amp; s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l;
            --r;
            if(r + 1 - l &gt; end + 1 - start) {
                start = l;
                end = r;
            }
            l = i;
            r = i + 1;
            while(l &gt;= 0 &amp;&amp; r &lt; len &amp;&amp; s[l] == s[r]) {
                --l;
                ++r;
            }
            ++l;
            --r;
            if(r + 1 - l &gt; end + 1 - start) {
                start = l;
                end = r;
            }
        }
        return s.substr(start, end + 1 - start);
    }
};