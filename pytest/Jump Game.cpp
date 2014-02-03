class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int far = 0;
        if(n &lt; 2) {
            return true;
        }
        int cur = 0;
        while(true) {
            far = max(far, A[cur] + cur);
            while(cur &lt; n &amp;&amp; cur &lt; far) {
                if(far &gt;= (n - 1)) {
                    return true;
                }
                far = max(far, A[cur] + cur);
                ++cur;
            }
            if(cur &lt; n &amp;&amp; A[cur] == 0) {
                return false;
            }
        }
    }
};