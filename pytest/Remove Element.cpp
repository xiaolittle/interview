class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        int j = i;
        while(j &lt; n) {
            while(j &lt; n &amp;&amp; A[j] == elem) {
                ++j;
            }
            if(j &lt; n) {
                A[i++] = A[j++];
            }
        }
        return i;
    }
};