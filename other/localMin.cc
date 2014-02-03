#include <stdio.h>
#include <vector>

using namespace std;

int localMin(const vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return -1;
    }
    int low = 0;
    int high = n - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(mid == 0) {
            if(A[mid] < A[mid + 1]) {
                return mid;
            }
            low = mid + 1;
        } else if(mid == n - 1) {
            if(A[mid] < A[mid - 1]) {
                return mid;
            }
            high = mid - 1;
        } else if(A[mid] < A[mid - 1] && A[mid] < A[mid + 1]) {
            return mid;
        } else if(A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("hahaha\n");
    return low;
}

int main() {
    vector<int> A = {2,1,4,5,6,4,5};
    int ans = localMin(A);
    printf("%d\n",ans);
    return 0;
}
