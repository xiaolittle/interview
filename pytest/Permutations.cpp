class Solution {
public:
    void getPermutations(vector&lt;vector&lt;int&gt; &gt; &amp;ans, vector&lt;int&gt; num, int dep) {
        if(dep == num.size()) {
            ans.push_back(num);
            return;
        }
        
        for(int i = dep; i &lt; num.size(); ++i) {
            swap(num[dep], num[i]);
            getPermutations(ans, num, dep + 1);
            swap(num[dep], num[i]);
        }
    }
    
    vector&lt;vector&lt;int&gt; &gt; permute(vector&lt;int&gt; &amp;num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; ans;
        int n = num.size();
        if(n == 0) {
            return ans;
        }
        
        getPermutations(ans, num, 0);
        return ans;
    }
};