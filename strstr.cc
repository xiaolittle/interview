#include <stdio.h>
#include <string.h>

    char *strStr(char *haystack, char *needle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strlen(needle);
        int m = strlen(haystack);
        printf("len = %d, m = %d\n", len, m);
        if(m < len) {
            return NULL;
        }
        if(len == 0) {
            return haystack;
        }
        int next[len];
        next[0] = 0;
        int p = 0;
        for(int i = 1; i < len; ++i) {
            while(p > 0 && needle[p] != needle[i]) {
                p = next[p - 1];
            }
            if(needle[p] == needle[i]) {
                ++p;
            }
            next[i] = p;
        }
        for(int i = 0; i < len; ++i) {
            printf("next[%d] = %d,",i, next[i]);
        }
        printf("\n");
//        return NULL;
        int q = 0;
        char* ans = NULL;
        for(int i = 0; i < m; ++i) {
            while(q > 0 && haystack[i] != needle[q]) {
                q = next[q - 1];
            }
            if(haystack[i] == needle[q]) {
                ++q;
            }
            if(q >= len) {
                return haystack + i - len; 
            }
        }
        return NULL;
    }
int main() {
    char* a = "babba";
    char* needle = "bbb";
    strStr(a, needle);
    return 0;
}
