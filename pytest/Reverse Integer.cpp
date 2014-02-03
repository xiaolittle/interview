class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long tmp = x;
        bool flag = false;
        if(x &lt; 0) {
            tmp = -x;
            flag = true;
        }
        int cur = 0;
        while(tmp &gt; 0) {
            cur += tmp % 10;
            tmp /= 10;
            if(tmp &gt; 0) {
                cur *= 10;
            }
        }
        return flag ? -cur:cur;
    }
};