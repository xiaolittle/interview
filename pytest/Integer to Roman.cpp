class Solution {
public:
    string intToRoman(int num) {
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
        int last = n - 1;
        string ans;
        while(num &gt; 0) {
            while(last &gt; 0 &amp;&amp; mp[last].first &gt; num) {
                --last;
            }
            ans += mp[last].second;
            num -= mp[last].first;
        }
        return ans;
    }
};