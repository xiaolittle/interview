class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; sub(n + 1);
        sub[0] = 1;
        sub[1] = 1;
        for(int i = 2; i &lt;= n; ++i) {
            int sum = 0;
            for(int j = 0; j &lt; i; ++j) {
                sum += sub[j]*sub[i - 1 - j];
            }
            sub[i] = sum;
        }
        return sub[n];
    }
};