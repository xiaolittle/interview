class Solution {
public:
    vector&lt;int&gt; grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = 0;
        vector&lt;int&gt; old;
        vector&lt;bool&gt; vst(1 &lt;&lt; n);
        old.push_back(num);
        vst[num] = true;
        for(int i = 1; i &lt; (1 &lt;&lt; n); ++i) {
            int j = 0;
            while(vst[old[i - 1] ^ (1 &lt;&lt; j)]) {
                ++j;
            }
            vst[old[i - 1] ^ (1 &lt;&lt; j)] = true;
            old.push_back(old[i - 1] ^ (1 &lt;&lt; j));
        }
        return old;
    }
};