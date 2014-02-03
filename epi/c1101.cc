int findFirstOcc(const int A[],const int &n,const int &k) {
    int l = 0; 
    int r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(A[mid] < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
