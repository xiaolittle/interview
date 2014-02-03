class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n &lt; 2) {
            return n;
        }
        int i = 0;
        int j = 0;
        while(j &lt; n) {
            while(j &lt; n - 1 &amp;&amp; A[j] == A[j + 1]) {
                j++;
            }
            A[i++] = A[j++];
        }
        return i;
    }
};