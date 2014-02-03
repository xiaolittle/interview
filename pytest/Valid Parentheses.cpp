class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack&lt;char&gt; st;
        int n = s.size();
        if(n == 0) {
            return true;
        }
        int i = 0;
        while(i &lt; n) {
            if(s[i] == &#39;(&#39; || s[i] == &#39;[&#39; || s[i] == &#39;{&#39;) {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                }
                if(s[i] == &#39;)&#39; &amp;&amp; st.top() != &#39;(&#39;) {
                    return false;
                }
                if(s[i] == &#39;}&#39; &amp;&amp; st.top() != &#39;{&#39;) {
                    return false;
                }
                if(s[i] == &#39;]&#39; &amp;&amp; st.top() != &#39;[&#39;) {
                    return false;
                }
                st.pop();
            }
            ++i;
        }
        return st.empty();
    }
};