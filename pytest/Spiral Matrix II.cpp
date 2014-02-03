class Solution {
public:
    vector&lt;vector&lt;int&gt; &gt; generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; matrix(n, vector&lt;int&gt; (n));
        if(n == 0) {
            return matrix;
        }
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int count = 1;
        while(true) {
            for(int i = left; i &lt;= right; ++i) {
                matrix[up][i] = count++;
            }
            ++up;
            if(up &gt; down) {
                break;
            }
            for(int i = up; i &lt;= down; ++i) {
                matrix[i][right] = count++;
            }
            --right;
            if(left &gt; right) {
                break;
            }
            for(int i = right; i &gt;= left; --i) {
                matrix[down][i] = count++;
            }
            --down;
            if(up &gt; down) {
                break;
            }
            for(int i = down; i &gt;= up; --i) {
                matrix[i][left] = count++;
            }
            ++left;
            if(left &gt; right) {
                break;
            }
        }
        
        return matrix;
    }
};