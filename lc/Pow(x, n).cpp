//var_dump(pow(2, 8)); // int(256)

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) {
			return 1.0;
		}
        long long num = n;
		bool sigh = false;
		if(n < 0) {
			sigh = true;
			num *= -1;
		}
		double y = x;
		double ans = 1.0;
		while(num) {
			if(num & 1) {
				ans *= y;
			}
			num >>= 1;
			y *= y;
		}

		return sigh ? 1.0/ans : ans;
    }
};