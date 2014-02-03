class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = s1.size();
        int n = s2.size();
        if(m != n) {
            return false;
        }
        if(m == 0) {
            return true;
        }
        if(s1 == s2) {
            return true;
        }
        string t1 = s1;
        string t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) {
            return false;
        }
        for(int i = 0; i &lt; m - 1; ++i) {
            if(isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) &amp;&amp; 
                isScramble(s1.substr(i + 1), s2.substr(i + 1))) {
                    return true;
                }
            if(isScramble(s1.substr(0, i + 1), s2.substr(m - 1 - i)) &amp;&amp; 
                isScramble(s1.substr(i + 1), s2.substr(0, m - 1 - i))) {
                    return true;
                }
        }
        return false;
    }
};