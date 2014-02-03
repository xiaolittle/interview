class Solution {
public:
    int findKthHelper(int A[], int m, int B[], int n, int k) {
        int l = n &lt; k ? (k - n - 1) : 0;
        int r = m &gt; k ? (k - 1) : (m - 1);
        int mid = (l + r) / 2;
        while(l &lt;= r) {
            mid = (l + r) / 2;
            int mini = (k - mid - 2) &gt;= 0 ? B[k - mid - 2] : numeric_limits&lt;int&gt;::min();
            int maxi = (k - mid - 1) &lt; n ? B[k - mid - 1] : numeric_limits&lt;int&gt;::max();
            if(mini &lt;= A[mid] &amp;&amp; maxi &gt;= A[mid]) {
                return mid;
            }
            if(mini &gt; A[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    
    int findKthElement(int A[], int m, int B[], int n, int k) {
        if(m == 0) {
            return B[k - 1];
        } else if(n == 0) {
            return A[k - 1];
        } else {
            int index = findKthHelper(A, m, B, n, k);
            if(index != -1) {
                return A[index];
            } else {
                index = findKthHelper(B, n, A, m, k);
                return B[index];
            }
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == 0 && n == 0) {
            return 0;
        }
        if((m + n) % 2 == 0) {
            return (findKthElement(A, m, B, n, (m + n) / 2) + findKthElement(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        } else {
            return findKthElement(A, m, B, n, (m + n) / 2 + 1);
        }
    }
};
