#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ans;
        int n = num.size();
        if(n < 3) {
            return 0;
        }
        ans = num[0] + num[1] + num[2];
        printf("num[0] = %d,num[1] = %d,num[2] = %d\n",num[0],num[1],num[2]);
        printf("ha ans = %d\n", ans);
        for(int i = 0; i < n;) {
            int start = i + 1;
            int end = n - 1;
            //int target = 0 - num[i];
            while(start < end) {
                if(abs(num[start] + num[end] + num[i] - target) < abs(ans - target)) {
                    printf("ans = %d,start = %d,end = %d,i = %d\n", ans,start, end, i);
                    ans = num[start] + num[end] + num[i];
                    int j = start + 1;
                    while(j < end && num[start] == num[j]) {
                        ++j;
                    }
                    start = j;
                } 
                if((num[start] + num[end] + num[i]) < target) {
                    start++;
                } else {
                    end--;
                }
            }
            int j = i + 1;
            while(j < n && num[i] == num[j]) {
                ++j;
            }
            i = j;
        }
        printf("ans = %d\n", ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a(6,1);
    a[1] = -3;
    a[2] = 3;
    a[3] = 5;
    a[4] = 4;
    s.threeSumClosest(a, 1);
}
