void merge_n_equal_m(int A[], int B[], int m, int n) {
    int c[];
    int i = 0;
    int j = 0;
    int k = 0;
    int c[];
    while(i < m && j < n) {
        if(A[i] == B[j] && (k == 0 || A[i] != A[i - 1])) {
            c[k++] = A[i++];
            ++j;
        } else if(A[i] < B[j]) {
            ++i;
        } else {
            ++j;
        }
    }
}

void merge_n<<m() {
    //binary search in m
}
