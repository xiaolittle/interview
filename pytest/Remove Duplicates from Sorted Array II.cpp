class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n &lt; 3) {
            return n;
        }
        int i = 0;
        int j = 0;
        while(j &lt; n) {
            int len = 0;
            while(j &lt; n - 1 &amp;&amp; A[j] == A[j + 1]) {
                j++;
                len++;
            }
            A[i++] = A[j];
            if(len &gt;= 1) {
                A[i++] = A[j];
            }
            j++;
        }
        return i;
    }
};