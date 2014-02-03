class Solution {
public:
    vector&lt;vector&lt;int&gt; &gt; generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; pascal;
        if(numRows == 0) {
            return pascal;
        }
        for(int i = 0; i &lt; numRows; ++i) {
            vector&lt;int&gt; cur;
            for(int j = 0; j &lt;= i; ++j) {
                if(j == 0 || j == i) {
                    cur.push_back(1);
                } else {
                    cur.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
                }
            }
            pascal.push_back(cur);
        }
        return pascal;
    }
};