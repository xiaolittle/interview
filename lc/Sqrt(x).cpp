class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
		unsigned int high = static_cast<long long>(x) + 1;
		int mid;

		while(low < high) {
			mid = low + (high - low) / 2;
			long long tmp = static_cast<long long>(mid)*mid;
			if(tmp <= x) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low - 1;
    }
};