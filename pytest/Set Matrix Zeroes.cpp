class Solution {
public:
    void setZeroes(vector&lt;vector&lt;int&gt; &gt; &amp;matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rowFlag = false;
        int colFlag = false;
        int m = matrix.size();
        if(m == 0) {
            return;
        }
        int n = matrix[0].size();
        for(int i = 0; i &lt; m; ++i) {
            for(int j = 0; j &lt; n; ++j) {
                if(i == 0 &amp;&amp; matrix[i][j] == 0) {
                    rowFlag = true;
                }
                if(j == 0 &amp;&amp; matrix[i][j] == 0) {
                    colFlag = true;
                }
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i &lt; m; ++i) {
            for(int j = 1; j &lt; n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowFlag) {
            for(int i = 0; i &lt; n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(colFlag) {
            for(int i = 0; i &lt; m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};