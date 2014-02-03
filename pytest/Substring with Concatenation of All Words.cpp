class Solution {
public:
    vector&lt;int&gt; findAns(vector&lt;int&gt; &amp;cnt, vector&lt;int&gt; &amp;str, int &amp;n) {
        int sum = 0;
        vector&lt;int&gt; ans;
        int i = 0;
        int m = str.size();
        while(i &lt; m) {
            if(str[i] == 0) {
                ++i;
                continue;
            }
            int j = i;
            sum = 0;
            vector&lt;int&gt; t(n + 1, 0);
            while(j &lt; m) {
                if(str[j] == 0) {
                    break;
                }
                if(t[str[j]] &lt; cnt[str[j]]) {
                    ++t[str[j]];
                    ++sum;
                    ++j;
                } else {
                    while(i &lt; j) {
                        --t[str[i]];
                        --sum;
                        if(str[i] == str[j]) {
                            ++i;
                            break;
                        }
                        ++i;
                    }
                    ++t[str[j]];
                    ++sum;
                    ++j;
                }
                
                if(sum == n) {
                    ans.push_back(i);
                    --sum;
                    --t[str[i]];
                    ++i;
                }
            }
            i = j;
        }
        
        return ans;
    }
    
    vector&lt;int&gt; findSubstring(string S, vector&lt;string&gt; &amp;L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = L.size();
        int m = S.size();
        int len = L[0].size();
        vector&lt;int&gt; ans;
        if(n == 0 || m == 0 || m &lt; n * len) {
            return ans;
        }
        unordered_map&lt;string, int&gt; mp;
        vector&lt;int&gt; cnt(n + 1, 0);
        for(int i = 0; i &lt; n; ++i) {
            if(mp.count(L[i]) == 0) {
                mp[L[i]] = i + 1;
            }
            ++cnt[mp[L[i]]];
        }
        
        for(int i = 0; i &lt; len; ++i) {
            vector&lt;int&gt; str;
            for(int j = 0; ((j + 1) * len + i) &lt;= m; ++j) {
                if(mp.count(S.substr(j * len + i, len)) &gt; 0) {
                    str.push_back(mp[S.substr(j * len + i, len)]);
                } else {
                    str.push_back(0);
                }
            }
            vector&lt;int&gt; curans = findAns(cnt, str, n);
            for(int k = 0; k &lt; curans.size(); ++k) {
                ans.push_back(i + curans[k] * len);
            }
        }
        
        return ans;
    }
};