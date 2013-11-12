class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ans = 0;
		bool flag = false;
		if(x < 0) {
			flag = true;
		}
		long long y = abs(x);
		while(y > 0) {
			ans = ans * 10 + y % 10;
			y /= 10;
		}
		if(flag) {
			return -1*ans;
		} else {
			return ans;
		}
    }
};