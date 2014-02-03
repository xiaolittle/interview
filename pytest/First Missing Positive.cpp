class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
            return 1;
        }
        int last = 0;
        while(last &lt; n) {
            while(last &lt; n &amp;&amp; (A[last] &lt;= 0 || A[last] == last + 1)) {
                ++last;
            }
            if(last &gt;= n) {
                break;
            }
            int pos = A[last];
            while(pos &gt; 0 &amp;&amp; pos &lt;= n &amp;&amp; A[pos - 1] != pos) {
                int tmp = A[pos - 1];
                A[pos - 1] = pos;
                pos = tmp;
            }
            ++last;
        }
        int ans = 1;
        while(ans &lt;= n &amp;&amp; A[ans - 1] == ans) {
            ++ans;
        }
        return ans;
    }
};