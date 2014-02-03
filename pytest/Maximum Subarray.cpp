class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
            return 0;
        }
        int ans = A[0];
        int left = A[0];
        for(int i = 1; i &lt; n; ++i) {
            if(left &gt; 0) {
                left += A[i];
            } else {
                left = A[i];
            }
            ans = max(ans, left);
        }
        return ans;
    }
};