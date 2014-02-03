#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
/*
int localMax(vector<int> A) {
    int n = A.size();
    if(n == 0) {
        return -1;
    }
    if(n == 1) {
        return A[0];
    } else if(n == 2) {
        return A[0] > A[1] ? 0:1;
    }
    int low = 0;
    int high = n - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        cout << "low = " << low << endl;
        cout << "mid = " << mid << endl;
        cout << "high = " << high << endl;
        if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid;
        } else if(A[mid] > A[mid - 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
*/

int localMax(const vector<int> &A) {
    if(A.size() == 0) {
        return -1;
    }
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while(low <= high) {
        if(low == high) {
            return A[mid];
        } else if(low == high - 1) {
            return A[low] > A[high] ? low:high;
        } else {
            mid = low + (high - low) / 2;
            if(A[mid - 1] < A[mid]) {
                low = mid;
            } else {
                high = mid;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> A = {5,4,3,2, 1};
    int ans = localMax(A);
    printf("%d\n",ans);
}
