class Solution {
public:
    int evalRPN(vector&lt;string&gt; &amp;tokens) {
        stack&lt;int&gt; st;
        int n = tokens.size();
        int i = 0;
        while(i &lt; n) {
            if(tokens[i].size() != 1 || (tokens[i][0] != &#39;+&#39; &amp;&amp; tokens[i][0] != &#39;-&#39; &amp;&amp;
                tokens[i][0] != &#39;*&#39; &amp;&amp; tokens[i][0] != &#39;/&#39;)) {
                    int m = tokens[i].size();
                    int res = 0;
                    int flag = 1;
                    int j = 0;
                    if(tokens[i][0] == &#39;-&#39;) {
                        flag = -1;
                        ++j;
                    }
                    for(; j &lt; m; ++j) {
                        res *= 10;
                        res += tokens[i][j] - &#39;0&#39;;
                    }
                    st.push(flag * res);
                } else {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    switch(tokens[i][0]) {
                        case &#39;+&#39;:
                        st.push(a + b);
                        break;
                        case &#39;-&#39;:
                        st.push(a - b);
                        break;
                        case &#39;*&#39;:
                        st.push(a * b);
                        break;
                        case &#39;/&#39;:
                        st.push(a / b);
                        break;
                    }
                }
                ++i;
        }
        return st.top();
    }
};