class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m + n - 1;
        int ia = m - 1;
        int ib = n - 1;
        while(i &gt;= 0) {
            if(ia &gt;= 0 &amp;&amp; ib &gt;= 0) {
                if(A[ia] &gt; B[ib]) {
                    A[i--] = A[ia--];
                } else {
                    A[i--] = B[ib--];
                }
            } else if(ia &gt;= 0) {
                A[i--] = A[ia--];
            } else {
                A[i--] = B[ib--];
            }
        }
    }
};