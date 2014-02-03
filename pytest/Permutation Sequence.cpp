class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k == 0) {
            return &quot;&quot;;
        }
        vector&lt;int&gt; mul(10, 1);
        for(int i = 1; i &lt;= 9; ++i) {
            mul[i] = mul[i - 1] * i;
        }
        vector&lt;char&gt; com;
        for(int i = 0; i &lt; n; ++i) {
            com.push_back(i + &#39;1&#39;);
        }
        string ans;
        for(int num = n; num &gt; 0; --num) {
            int sum = 0;
            int i = 0;
            for(; i &lt; n; ++i) {
                if(sum + mul[num - 1] &gt;= k) {
                    break;
                }
                sum += mul[num - 1];
            }
            int len = 0;
            ans += com[i];
            for(int j = 0; j &lt; com.size(); ++j) {
                if(j != i) {
                    com[len++] = com[j];
                }
            }
            com.pop_back();
            k -= sum;
        }
        return ans;
    }
};