class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0;
        int right = n - 1;
        int sum = 0;
        if(n &lt; 3) {
            return sum;
        }
        
        while(left &lt; right) {
            if(A[left] &lt;= A[right]) {
                if(A[left] &gt; A[left + 1]) {
                    sum += A[left] - A[left + 1];
                    A[left + 1] = A[left];
                }
                ++left;
            } else {
                if(A[right] &gt; A[right - 1]) {
                    sum += A[right] - A[right - 1];
                    A[right - 1] = A[right];
                }
                --right;
            }
        }
        return sum;
    }
};