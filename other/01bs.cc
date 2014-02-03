#include <stdio.h>
#include <vector>

using namespace std;

int binary_search(vector<int> onezero) {
    int n = onezero.size();
    int low = 0;
    int high = n - 1;
    while(low < high) {
        int mid = low + ((high - low) >> 1);
        if(onezero[mid] == 1) {
            high = mid - 1;
        } else {
            low = mid;
        }
    }
    return low;
}

int main() {
    vector<int> onezero(4,0);
    onezero[3] = 1;
    int ans = binary_search(onezero);
    printf("%d\n",ans);
    return 0;
}
