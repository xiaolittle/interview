class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i = 0; i &lt; n; ++i) {
            if(A[i] == target) {
                return true;
            }
        }
        return false;
    }
};