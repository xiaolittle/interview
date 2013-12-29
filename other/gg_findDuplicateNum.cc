#include <stdio.h>
#include <vector>

using namespace std;

int findDuplicate(const vector<int> &a) {
    int start = 1;
    int n = a.size();
    int end = n;
    
    while(start < end) {
        int mid = start + ((end - start)>>1);
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] <= mid) {
                count++;
            }
        }
            if(count <= mid) {
                start = mid + 1;
            } else {
                end = mid;
            }
            printf("start = %d,end = %d, mid = %d, count = %d\n", start, end, mid, count);
    }
    
    return start;
}

int main(int argc, char *argv[]) {
    
    vector<int> a;
    a.push_back(1);
//    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
   // a.push_back(4);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    int ans = findDuplicate(a);
    printf("%d\n",ans);
    
    return 0;
}
