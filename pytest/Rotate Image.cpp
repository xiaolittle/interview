class Solution {
public:
    void rotate(vector&lt;vector&lt;int&gt; &gt; &amp;matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if(n &lt; 2) {
            return;
        }
        for(int level = 0; level &lt; n / 2; ++level) {
            for(int i = level; i &lt; n - 1 - level; ++i) {
                int tmp = matrix[level][i];
                matrix[level][i] = matrix[n - 1 - i][level];
                matrix[n - 1 - i][level] = matrix[n - 1 - level][n - 1 - i];
                matrix[n - 1 - level][n - 1 - i] = matrix[i][n - 1 - level];
                matrix[i][n - 1 - level] = tmp;
            }
        }
        
    }
};