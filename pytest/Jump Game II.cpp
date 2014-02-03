class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int far = 0;
        if(n &lt; 2) {
            return 0;
        }
        int cur = 0;
        int curstep = 0;
        int last = 0;
        while(true) {
            ++curstep;
            far = max(far, A[cur] + cur);
            if(far &gt;= (n - 1)) {
                return curstep;
            }
            last = far;
            while(cur &lt; n &amp;&amp; cur &lt; last) {
                if(far &gt;= (n - 1)) {
                    return curstep + 1;
                }
                far = max(far, A[cur] + cur);
                ++cur;
            }
        }
    }
};