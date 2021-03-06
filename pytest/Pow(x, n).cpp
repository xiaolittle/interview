class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
            return 1;
        } else if(n == 1) {
            return x;
        }
        double ans = 1;
        bool flag = true;
        if(n &lt; 0) {
            flag = false;
            n = -n;
        }
        while(n) {
            if(n % 2 != 0) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        if(flag) {
            return ans;
        }
        return 1.0/ans;
    }
};