#include <string>
#include <stdio.h>
#include <string.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equalChar(const char &a, const char &b) {
        printf("%c, %c\n",a,b);
        if(((a - 'a') == (b - 'a')) || ((a - 'A') == (b - 'a')) || ((a - 'a') == (b - 'A'))) {
            return true;
        }
        printf("hahaha\n");
        return false;
    }
    
    bool isChar(const char &ch) {
        if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            if(!isChar(s[left])) {
                left++;
                printf("left = %d\n",left);
                continue;
            }
            if(!isChar(s[right])) {
                --right;
                printf("right = %d\n", right);
                continue;
            }
            if(!equalChar(s[left], s[right])) {
                printf("ttttttttt\n");
                return false;
            }
            printf("%d, right = %d\n",left, right);
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    Solution s;
    bool ans = s.isPalindrome("la2");
    printf("%d\n", ans);
    unordered_map<int,int> ha;
    ha[10] = 5;
    printf("%d\n", ha[10]);
    return 1;
}
