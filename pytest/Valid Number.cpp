class Solution {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s == NULL) {
            return false;
        }
        int n = strlen(s);
        int begin = 0;
        while(begin &lt; n &amp;&amp; s[begin] == &#39; &#39;) {
            ++begin;
        }
        if(begin == n) {
            return false;
        }
        int end = n - 1;
        while(end &gt; begin &amp;&amp; s[end] == &#39; &#39;) {
            --end;
        }
        ++end;
        int pos = begin;
        while(pos &lt; end &amp;&amp; s[pos] != &#39;e&#39;) {
            pos++;
        }
        if(s[begin] == &#39;+&#39; || s[begin] == &#39;-&#39;) {
            ++begin;
        }
        if(begin == pos || (begin + 1 == pos &amp;&amp; s[begin] == &#39;.&#39;)) {
            return false;
        }
        bool dot = false;
        while(begin &lt; pos) {
            if(s[begin] == &#39;.&#39;) {
                if(dot) {
                    return false;
                }
                dot = true;
                begin++;
            } else {
                if(!(s[begin] &gt;= &#39;0&#39; &amp;&amp; s[begin] &lt;= &#39;9&#39;)) {
                    return false;
                }
                begin++;
            }
        }
        if(s[pos] != &#39;e&#39;) {
            return true;
        }
        begin = pos + 1;
        if(s[pos] == &#39;e&#39; &amp;&amp; ((pos + 1)== end)) {
            return false;
        }
        if(s[begin] == &#39;+&#39; || s[begin] == &#39;-&#39;) {
            ++begin;
        }
        if(begin &gt;= end) {
            return false;
        }
        while(begin &lt; end) {
            if(!(s[begin] &gt;= &#39;0&#39; &amp;&amp; s[begin] &lt;= &#39;9&#39;)) {
                    return false;
                }
                begin++;
        }
        return true;
    }
};