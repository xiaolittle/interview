class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x &lt; 0) {
            return false;
        }
        if(x &lt; 10) {
            return true;
        }
        long long ten = 1;
        while(ten &lt;= x) {
            ten *= 10;
        }
        ten /= 10;
        int y = x;
        while(y &gt; 0) {
            if(y / ten != y % 10) {
                return false;
            }
            y = y % ten;
            y /= 10;
            if(y &lt; 10) {
                return true;
            }
            ten /= 100;
        }
        return true;
    }
};