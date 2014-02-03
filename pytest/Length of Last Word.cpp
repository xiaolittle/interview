class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        if(*s == 0) {
            return ans;
        }
        while(*s != 0) {
            while(*s != 0 &amp;&amp; *s == &#39; &#39;) {
                s++;
            }
            if(*s == 0) {
                break;
            }
            ans = 0;
            while(*s != 0 &amp;&amp; *s != &#39; &#39;) {
                ans++;
                s++;
            }
        }
        return ans;
    }
};