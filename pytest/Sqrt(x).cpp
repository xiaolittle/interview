class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = x;
        while(low &lt; high) {
            int mid = low + (high - low)/2 + 1;
            if(x / mid == mid) {
                return mid;
            } else if(x / mid &lt; mid) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        return high;
    }
};