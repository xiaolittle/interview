class Solution {
public:
    void solve(vector&lt;vector&lt;char&gt;&gt; &amp;board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack&lt;pair&lt;int, int&gt; &gt; st;
        int m = board.size();
        if(m &lt; 3) {
            return;
        }
        int n = board[0].size();
        if(n &lt; 3) {
            return;
        }
        
        for(int i = 0; i &lt; m; ++i) {
            for(int j = 0; j &lt; n; ++j) {
                if(board[i][j] == &#39;O&#39; &amp;&amp; (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    st.push(make_pair(i, j));
                    board[i][j] = &#39;N&#39;;
                }
            }
        }
        const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(!st.empty()) {
            pair&lt;int, int&gt; cur = st.top();
            st.pop();
            for(int i = 0; i &lt; 4; ++i) {
                int row = cur.first + dir[i][0];
                int col = cur.second + dir[i][1];
                if(row &gt;= 0 &amp;&amp; row &lt; m &amp;&amp; col &gt;= 0 &amp;&amp; col &lt; n &amp;&amp; board[row][col] == &#39;O&#39;) {
                    st.push(make_pair(row, col));
                    board[row][col] = &#39;N&#39;;
                }
            }
        }
        
        for(int i = 0; i &lt; m; ++i) {
            for(int j = 0; j &lt; n; ++j) {
                if(board[i][j] == &#39;O&#39;) {
                    board[i][j] = &#39;X&#39;;
                } else if(board[i][j] == &#39;N&#39;) {
                    board[i][j] = &#39;O&#39;;
                }
            }
        }
    }
};