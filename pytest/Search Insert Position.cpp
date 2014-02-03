class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = n;
        if(n == 0) {
            return 0;
        }
        while(low &lt; high) {
            int mid = low + (high - low) / 2;
            if(A[mid] &lt; target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
};