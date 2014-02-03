class Solution {
public:
    string longestCommonPrefix(vector&lt;string&gt; &amp;strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        if(n == 0) {
            return &quot;&quot;;
        }
        if(n == 1) {
            return strs[0];
        }
        int len = 0;
        while(true) {
            int i = 1;
            while(i &lt; n &amp;&amp; strs[i][len] != 0 &amp;&amp; strs[i][len] == strs[0][len]) {
                ++i;
            }
            if(i &lt; n) {
                break;
            }
            ++len;
        }
        return strs[0].substr(0, len);
    }
};