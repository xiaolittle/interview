class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
        int m = S.size();
        int n = T.size();
        if(m &lt; n || n == 0) {
            return ans;
        }
        map&lt;char, int&gt; mp;
        for(int i = 0; i &lt; n; ++i) {
            if(mp.count(T[i]) != 0) {
                mp[T[i]]++;
            } else {
                mp[T[i]] = 1;
            }
        }
        int count = 0;
        map&lt;char, int&gt; exist;
        int begin = 0;
        int end = 0;
        int curlen = m;
        while(true) {
            while(end &lt; m &amp;&amp; count &lt; n) {
                if(mp.count(S[end])) {
                    if(exist.count(S[end])) {
                        exist[S[end]]++;
                        if(exist[S[end]] &lt;= mp[S[end]]) {
                            ++count;
                        }
                    } else {
                        exist[S[end]] = 1;
                        ++count;
                    }
                }
                ++end;
            }
            if(count == n) {
                while(begin &lt; end &amp;&amp; (mp.count(S[begin]) == 0 || mp[S[begin]] &lt; exist[S[begin]])) {
                    if(exist.count(S[begin])) {
						--exist[S[begin]];
					}
                    ++begin;
                }
                if(end - begin &lt;= curlen) {
                    curlen = end - begin;
                    ans = S.substr(begin, curlen);
                }
            }
            if(end == m) {
                break;
            }
            --exist[S[begin]];
            --count;
            ++begin;
        }
        return ans;
    }
};