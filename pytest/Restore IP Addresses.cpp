class Solution {
public:
    bool num(string sub) {
        if(sub.size() == 0 || sub.size() &gt; 3) {
            return false;
        }
        if(sub.size() &gt; 1 &amp;&amp; sub[0] == &#39;0&#39;) {
            return false;
        }
        int sum = 0;
        int ten = 1;
        for(int i = 0; i &lt; sub.size(); ++i) {
            sum += sub[i] - &#39;0&#39;;
            if(i &lt; sub.size() - 1) {
                sum *= 10;
            }
            if(sum &gt; 255) {
                return false;
            }
        }
        return true;
    }
    
    vector&lt;string&gt; restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;string&gt; ans;
        int n = s.size();
        if(n &lt; 4) {
            return ans;
        }
        for(int i = 0; i &lt; 3; ++i) {
            if(!num(s.substr(0, i + 1))) {
                continue;
            }
            for(int j = 0; j &lt; 3 &amp;&amp; ((i + 1 + j) &lt; n); ++j) {
                if(!num(s.substr(i + 1, j + 1))) {
                    continue;
                }
                for(int k = 0; k &lt; 3 &amp;&amp; ((i + j + k + 2) &lt; n); ++k) {
                    if(!num(s.substr(i + j + 2, k + 1)) || !num(s.substr(i + j + k + 3))) {
                        continue;
                    }
                    string cur = s.substr(0, i + 1);
                    cur += &#39;.&#39;;
                    cur += s.substr(i + 1, j + 1);
                    cur += &#39;.&#39;;
                    cur += s.substr(i + j + 2, k + 1);
                    cur += &#39;.&#39;;
                    cur += s.substr(i + j + k + 3);
                    ans.push_back(cur);
                }
            }
        }
        
        return ans;
    }
};