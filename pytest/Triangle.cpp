class Solution {
public:
    int minimumTotal(vector&lt;vector&lt;int&gt; &gt; &amp;triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = triangle.size();
        if(m == 0) {
            return 0;
        }
        vector&lt;int&gt; last = triangle[0];
        for(int i = 1; i &lt; m; ++i) {
            vector&lt;int&gt; cur;
            for(int j = 0; j &lt; i + 1; ++j) {
                if(j == 0) {
                    cur.push_back(last[j] + triangle[i][j]);
                } else if(j == i){
                    cur.push_back(last[j - 1] + triangle[i][j]);
                } else {
                    cur.push_back((min(last[j - 1], last[j]) + triangle[i][j]));
                }
            }
            last = cur;
        }
        int ans = last[0];
        for(int i = 1; i &lt; last.size(); ++i) {
            ans = min(ans, last[i]);
        }
        return ans;
    }
};