class Solution {
public:
    int longestConsecutive(vector&lt;int&gt; &amp;num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set&lt;int&gt; st;
        for(int i = 0; i &lt; num.size(); ++i) {
            st.insert(num[i]);
        }
        int ans = 0;
        for(int i = 0; i &lt; num.size(); ++i) {
            int cnt = 1;
            if(st.find(num[i]) == st.end()) {
                continue;
            }
            int tmp = num[i];
            st.erase(tmp);
            int j = 1;
            while(st.find(tmp + j) != st.end()) {
                ++cnt;
                st.erase(tmp + j);
                ++j;
            }
            j = -1;
            while(st.find(tmp + j) != st.end()) {
                ++cnt;
                st.erase(tmp + j);
                --j;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};