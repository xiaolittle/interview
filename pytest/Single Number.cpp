class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = A[0];
        for(int i = 1; i &lt; n; ++i) {
            ans ^= A[i];
        }
        return ans;
    }
};