class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;pair&lt;int, string&gt; &gt; mp;
        mp.push_back(make_pair(1, &quot;I&quot;));
        mp.push_back(make_pair(4, &quot;IV&quot;));
        mp.push_back(make_pair(5, &quot;V&quot;));
        mp.push_back(make_pair(9, &quot;IX&quot;));
        mp.push_back(make_pair(10, &quot;X&quot;));
        mp.push_back(make_pair(40, &quot;XL&quot;));
        mp.push_back(make_pair(50, &quot;L&quot;));
        mp.push_back(make_pair(90, &quot;XC&quot;));
        mp.push_back(make_pair(100, &quot;C&quot;));
        mp.push_back(make_pair(400, &quot;CD&quot;));
        mp.push_back(make_pair(500, &quot;D&quot;));
        mp.push_back(make_pair(900, &quot;CM&quot;));
        mp.push_back(make_pair(1000, &quot;M&quot;));
        
        int n = mp.size();
        int m = s.size();
        int ans = 0;
        if(m == 0) {
            return ans;
        }
        int i = n - 1;
        int j = 0;
        while(j &lt; m) {
            while(i &gt;= 0) {
                if(j &lt; (m - 1)) {
                    if(s.substr(j, 2) == mp[i].second) {
                        break;
                    }
                }
                if(s.substr(j, 1) == mp[i].second) {
                    break;
                }
                --i;
            }
            if(mp[i].second.size() == 2) {
                j += 2;
            } else {
                j += 1;
            }
            ans += mp[i].first;
        }
        return ans;
        
    }
};