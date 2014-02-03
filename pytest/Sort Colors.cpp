class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n &lt; 2) {
            return;
        }
        int zero = 0;
        int one = 0;
        int two = n - 1;
        while(zero &lt; n &amp;&amp; A[zero] == 0) {
            ++zero;
            ++one;
        }
        if(zero == n) {
            return;
        }
        while(two &gt;= 0 &amp;&amp; A[two] == 2) {
            --two;
        }
        if(two &lt; zero) {
            return;
        }
        
        while(one &lt;= two) {
            if(A[one] == 1) {
                ++one;
                continue;
            } else if(A[one] == 0) {
                swap(A[one], A[zero]);
                ++one;
                ++zero;
            } else {
                if(A[two] == 1) {
                    swap(A[one], A[two]);
                    ++one;
                    --two;
                } else {
                    if(one == zero) {
                        swap(A[zero], A[two]);
                        ++one;
                        ++zero;
                        --two;
                    } else {
                        int tmp = A[zero];
                        A[two] = 2;
                        A[zero] = 0;
                        A[one] = tmp;
                        ++zero;
                        --two;
                    }
                }
            }
            
            while(one &lt;= two &amp;&amp; A[two] == 2) {
                --two;
            }
        }
    }
};