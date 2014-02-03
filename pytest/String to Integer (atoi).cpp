class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ans = 0;
        int i = 0;
        while(str[i] != 0 &amp;&amp; str[i] == &#39; &#39;) {
            ++i;
        }
        bool flag = false;
        if(str[i] == 0) {
            return (int)ans;
        }
        if(!(str[i] == &#39;-&#39; || str[i] == &#39;+&#39; || (str[i] &gt;= &#39;0&#39; &amp;&amp; str[i] &lt;= &#39;9&#39;))) {
            return (int)ans;
        }
        if(str[i] == &#39;-&#39;) {
            flag = true;
            ++i;
        } else if(str[i] == &#39;+&#39;) {
            ++i;
        }
        while(str[i] != 0 &amp;&amp; (str[i] &gt;= &#39;0&#39; &amp;&amp; str[i] &lt;= &#39;9&#39;)) {
            ans *= 10;
            ans += str[i] - &#39;0&#39;;
            if(ans &gt; numeric_limits&lt;int&gt;::max()) {
                return flag ? numeric_limits&lt;int&gt;::min() : numeric_limits&lt;int&gt;::max();
            }
            ++i;
        }
        int intans = ans;
        return flag ? -intans : intans;
    }
};