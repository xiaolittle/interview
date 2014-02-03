class Solution {
public:
    vector&lt;int&gt; getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;int&gt; cur;
//        if(rowIndex == 0) {
 //           return cur;
//        }
        vector&lt;int&gt; last;
        last.push_back(1);
        for(int i = 1; i &lt;= rowIndex; ++i) {
            cur.clear();
            for(int j = 0; j &lt;= i; ++j) {
                if(j == 0 || j == i) {
                    cur.push_back(1);
                } else {
                    cur.push_back(last[j - 1] + last[j]);
                }
            }
            last = cur;
        }
        return last;
    }
};