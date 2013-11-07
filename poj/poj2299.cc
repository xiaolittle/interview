#include <stdio.h>
#include <vector>

using namespace std;

struct Node{
    int value;
    int index;
    int count;
    Node(int x, int y, int z):value(x), index(y), count(z) {}
};

void unionsort(vector<Node> &arr,int begin, int end) {
    if(begin >= end) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    unionsort(arr, begin, mid);
    unionsort(arr, mid + 1, end);
    int left = begin;
    int right = mid + 1;
    vector<Node> tmp;
    while(left <= mid && right <= end) {
        if(arr[left].value > arr[right].value) {
            tmp.push_back(arr[left]);
            ++left;
        } else {
            arr[right].count += (left - begin);
            tmp.push_back(arr[right]);
            ++right;
        }
    }
    while(left <= mid) {
        tmp.push_back(arr[left]);
        ++left;
    }
    while(right <= end) {
        arr[right].count += mid - begin + 1;
        tmp.push_back(arr[right]);
        ++right;
    }
    for(int i = 0; i < tmp.size(); ++i){
        arr[begin++] = tmp[i];
    }
}

int solve(vector<Node> &arr, const int &n) {
    if(n == 1) {
        return 0;
    }
    vector<int> help(n, 0);
    unionsort(arr, 0, n - 1);
    long long ans = 0;
    for( int i = 0; i < n; ++i) {
        ans += arr[i].count;
//        printf("value = %d,%d ", arr[i].value, arr[i].count);
//        printf("arr = %d ", arr[i]);
    }
//    printf("henghengheng\n");
    return ans;
}

int main() {
    int n;
    while(true) {
        scanf("%d",&n);
        if(n == 0) {
            break;
        }
        vector<Node> arr;
        int tmpint;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &tmpint);
            arr.push_back(Node(tmpint, i, 0));
        }
        long long ans = solve(arr, n);
        printf("%lld\n",ans);
    }
    return 0;
}
