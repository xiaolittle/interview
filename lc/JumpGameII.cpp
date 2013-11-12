class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n <= 1) {
			return 0;
		}
		vector<int> B(n, numeric_limits<int>::max());

    	B[0] = 0;

		int maxi = 0;
		int cur = 0;
		int i = 0;
		while(i <= maxi) {
			if((A[i] + i) > maxi) {
				cur = i + 1;
				maxi = A[i] + i;
				if(maxi >= n - 1) {
					return B[i] + 1;
				}
				while(cur <= maxi) {
					B[cur] = min(B[cur], B[i] + 1);
					cur++;
				}
			}
			++i;
		}
		return -1;
    }
};