class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = n - 1;
        if(n == 0) {
            return -1;
        }
        while(low &lt;= high) {
            int mid = low + (high - low) / 2;
            if(A[mid] == target) {
                return mid;
            }
            if(A[low] &lt;= A[mid]) {
                if(A[low] &lt;= target &amp;&amp; target &lt; A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(A[mid] &lt; target &amp;&amp; target &lt;= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};