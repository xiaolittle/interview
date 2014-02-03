class Solution {
public:
    const char* Strstr(const char *s, const char *p) {
        if(*s == 0) {
            return *p == 0 ? s : NULL;
        }
        int m = strlen(s);
        int n = strlen(p);
        if(m < n) {
            return NULL;
        }
        for(int i = 0; i + n <= m; ++i) {
            int k = 0;
            while(k < n && (s[i + k] == p[k] || p[k] == '?')) {
                ++k;
            }
            if(k >= n) {
                return s + i;
            }
        }
        return NULL;
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0 && *p == 0) {
            return true;
        }
        if(*p == 0) {
            return false;
        }
        int m = strlen(s);
        int n = strlen(p);
        vector<string> sub;
        int i = 0;
        while(i < n) {
            int j = i;
            string str;
            while(j < n && p[j] != '*') {
                str += p[j];
                ++j;
            }
            sub.push_back(str);
            i = j + 1;
        }
        if(p[n - 1] == '*') {
            sub.push_back(&quot;&quot;);
        }
        if(sub.size() == 1) {
            return (m == n && Strstr(s, p));
        }
        int cur = 0;
        for(int i = 0; < sub.size(); ++i) {
            const char* pos = NULL;
            if(i == 0) {
                if(Strstr(s, sub[i].c_str()) != s) {
                    return false;
                }
                cur += sub[i].size();
            } else if(i == sub.size() - 1) {
                if((cur + sub[i].size()) > m || Strstr(s + m - sub[i].size(), sub[i].c_str()) == NULL) {
                    return false;
                }
            } else {
                pos = Strstr(s + cur, sub[i].c_str());
                if(pos == NULL) {
                    return false;
                }
                cur = pos - s + sub[i].size();
            }
        }
        return true;
    }
};
