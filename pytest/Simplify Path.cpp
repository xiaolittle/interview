class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        int n = path.size();
        if(n == 0) {
            return &quot;/&quot;;
        }
        deque&lt;string&gt; doc;
        int j,i = 0;
        while(i &lt; n) {
            while(i &lt; n &amp;&amp; (path[i] == &#39;/&#39; || path[i] == &#39; &#39;)) {
                ++i;
            }
            j = i;
            while(j &lt; n &amp;&amp; path[j] != &#39;/&#39;) {
                ++j;
            }
            if(i != j) {
                if(path.substr(i, j - i) == &quot;..&quot;) {
                    if(!doc.empty()) {
                        doc.pop_back();
                    }
                } else if(path.substr(i, j - i) != &quot;.&quot;) {
                    doc.push_back(path.substr(i, j - i));
                }
            }
            i = j;
        }
        while(!doc.empty()) {
            ans += &quot;/&quot;;
            ans += doc.front();
            doc.pop_front();
        }
        if(ans.size() == 0) {
            ans += &quot;/&quot;;
        }
        return ans;
    }
};