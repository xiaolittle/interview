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
        for(int i = dep; i &lt; candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            findCombination(candidates, target, ans, i, cur, sum + candidates[i]);
            cur.pop_back();
        }
        
    }
    vector&lt;vector&lt;int&gt; &gt; combinationSum(vector&lt;int&gt; &amp;candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        vector&lt;vector&lt;int&gt; &gt; ans;
        if(candidates.size() == 0) {
            return ans;
        }
        int dep = 0;
        vector&lt;int&gt; cur;
        int sum = 0;
        findCombination(candidates, target, ans, dep, cur, sum);
    }
};