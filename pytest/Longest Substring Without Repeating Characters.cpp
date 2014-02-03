class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set&lt;char&gt; hash;
        int n = s.size();
        if(n &lt; 2) {
            return n;
        }
        hash.insert(s[0]);
        int len = 1;
        int ans = 1;
        int i = 1;
        while(i &lt; n) {
            if(hash.find(s[i]) == hash.end()) {
                hash.insert(s[i]);
                ++len;
                ans = max(ans, len);
            } else {
                while(s[i - len] != s[i]) {
                    hash.erase(s[i - len]);
                    --len;
                }
            }
            ++i;
        }
        ans = max(ans, len);
        return ans;
    }
};