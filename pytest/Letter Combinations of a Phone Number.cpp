class Solution {
public:
    void getCombinations(vector&lt;string&gt; &amp;ans, vector&lt;string&gt; &amp;num, string &amp;digits, string cur, int dep) {
        if(cur.length() == digits.length()) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i &lt; num[(int)(digits[dep] - &#39;2&#39;)].size(); ++i) {
            cur += num[digits[dep] - &#39;2&#39;][i];
            getCombinations(ans, num, digits, cur, dep + 1);
            cur.erase(cur.length() - 1, 1);
        }
    }
    vector&lt;string&gt; letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;string&gt; num;
        num.push_back(&quot;abc&quot;);
        num.push_back(&quot;def&quot;);
        num.push_back(&quot;ghi&quot;);
        num.push_back(&quot;jkl&quot;);
        num.push_back(&quot;mno&quot;);
        num.push_back(&quot;pqrs&quot;);
        num.push_back(&quot;tuv&quot;);
        num.push_back(&quot;wxyz&quot;);
        vector&lt;string&gt; ans;
//        if(digits.size() == 0) {
//            ans.push_back(&quot;&quot;);
 //           return ans;
 //       }
        string cur;
        getCombinations(ans, num, digits, cur, 0);
        return ans;
    }
};