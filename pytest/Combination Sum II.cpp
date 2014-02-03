class Solution {
public:
    void findCombination(vector&lt;int&gt; &amp;candidates, int target, vector&lt;vector&lt;int&gt; &gt; &amp;ans, int dep, vector&lt;int&gt; cur, int sum) {
        if(sum &gt; target) {
            return;
        }
        if(sum == target) {
            ans.push_back(cur);
            return;
        }
        for(int i = dep; i &lt; candidates.size();) {
            cur.push_back(candidates[i]);
            findCombination(candidates, target, ans, i + 1, cur, sum + candidates[i]);
            cur.pop_back();
            int curdep = i + 1;
            while(curdep &lt; candidates.size() &amp;&amp; candidates[i] == candidates[curdep]) {
                curdep++;
            }
            i = curdep;
        }
    }
    
    vector&lt;vector&lt;int&gt; &gt; combinationSum2(vector&lt;int&gt; &amp;num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector&lt;vector&lt;int&gt; &gt; ans;
        if(num.size() == 0) {
            return ans;
        }
        int dep = 0;
        vector&lt;int&gt; cur;
        int sum = 0;
        findCombination(num, target, ans, dep, cur, sum);
        return ans;
    }
};