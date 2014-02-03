class Solution {
public:
    int lowerBound(int A[], int n, int target) {
        if(n == 0) {
            return 0;
        }
        int low = 0;
        int high = n;
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
    
    int higherBound(int A[], int n, int target) {
        if(n == 0) {
            return 0;
        }
        int low = 0;
        int high = n;
        while(low &lt; high) {
            int mid = low + (high - low) / 2;
            if(A[mid] &lt;= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
    
    vector&lt;int&gt; searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = lowerBound(A, n, target);
        int high = higherBound(A, n, target);
        if(low == high) {
            return vector&lt;int&gt; (2, -1);
        } else {
            vector&lt;int&gt; ans;
            ans.push_back(low);
            ans.push_back(high - 1);
            return ans;
        }
    }
};