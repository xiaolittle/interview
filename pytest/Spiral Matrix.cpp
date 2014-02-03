class Solution {
public:
    vector&lt;int&gt; spiralOrder(vector&lt;vector&lt;int&gt; &gt; &amp;matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; ans;
        int m = matrix.size();
        if(m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        while(true) {
            for(int i = left; i &lt;= right; ++i) {
                ans.push_back(matrix[up][i]);
            }
            ++up;
            if(up &gt; down) {
                break;
            }
            for(int i = up; i &lt;= down; ++i) {
                ans.push_back(matrix[i][right]);
            }
            --right;
            if(left &gt; right) {
                break;
            }
            for(int i = right; i &gt;= left; --i) {
                ans.push_back(matrix[down][i]);
            }
            --down;
            if(up &gt; down) {
                break;
            }
            for(int i = down; i &gt;= up; --i) {
                ans.push_back(matrix[i][left]);
            }
            ++left;
            if(left &gt; right) {
                break;
            }
        }
        
        return ans;
    }
};