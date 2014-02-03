class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        for(int i = 0; i &lt; 32; ++i) {
            int sum = 0;
            int x = (1 &lt;&lt; i);
            for(int j = 0; j &lt; n; ++j) {
                if(A[j] &amp; x) {
                    sum++;
                }
            }
            if(sum % 3) {
                ans |= x;
            }
        }
        return ans;
    }
};