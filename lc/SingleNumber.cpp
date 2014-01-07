class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        while (n-- > 1) {
            A[n - 1] ^= A[n];
        }
        return A[0];
    }
};
