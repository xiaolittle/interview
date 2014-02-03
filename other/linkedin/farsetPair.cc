#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

void farestPair(const vector<int> &height) {
    int n = height.size();
    vector<int> left;
    int start = -1;
    int end = -1;
    left.push_back(0);
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        int low = 0;
        int high = left.size();
        if(height[i] < height[left[left.size() - 1]]) {
            left.push_back(i);
        } else {
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(height[left[mid]] >= height[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
      //      if(i == 8 || i == 9) {
      //          printf("i = %d,low = %d,size = %d\n",i,low,left.size());
      //      }
            if((i - left[low]) > ans) {
                start = left[low];
                end = i;
            }
            ans = max(ans, i - left[low]);
        }
    }
    
    printf("%d, %d\n",start, end);
}

int main() {
//    vector<int> h = {1,7,4,0,9,4,8,8,2,4};
    //vector<int> h = {5,3,4,2,5,1,1};
  vector<int> h = {0,5,2,2,7,3,7,9,0,2};  
    farestPair(h);
    return 0;
}
