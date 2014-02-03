class Solution {
public:
    vector&lt;string&gt; anagrams(vector&lt;string&gt; &amp;strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map&lt;string, vector&lt;string&gt; &gt; mp;
        string tmp;
        for(int i = 0; i &lt; strs.size(); ++i) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        vector&lt;string&gt; ans;
        for(map&lt;string, vector&lt;string&gt;&gt;::iterator p = mp.begin(); p != mp.end(); ++p) {
            if((p-&gt;second).size() &gt; 1) {
                for(int i = 0; i &lt; (p-&gt;second).size(); ++i)
                    ans.push_back((p-&gt;second)[i]);
            }
        }
        return ans;
    }
};