class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        for(i = 0; i < n; ++i) {
            if(A[i] == target) {
                return true;
            }
        }
        return false;
    }
};