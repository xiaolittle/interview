class Solution {
public:
    bool searchMatrix(vector&lt;vector&lt;int&gt; &gt; &amp;matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if(m == 0) {
            return false;
        }
        int n = matrix[0].size();
        int low = 0;
        int high = m;
        while(low &lt; high) {
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] &lt;= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(high == 0) {
            return false;
        }
        int line = high - 1;
        low = 0;
        high = n - 1;
        while(low &lt;= high) {
            int mid = low + (high - low) / 2;
            if(matrix[line][mid] == target) {
                return true;
            }else if(matrix[line][mid] &lt; target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};