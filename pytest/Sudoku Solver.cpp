class Solution {
public:
    struct Node {
        int r;
        int c;
        int b;
        Node(int x, int y, int z): r(x), c(y), b(z) {}
    };
    
    void solveSudoku(vector&lt;vector&lt;char&gt; &gt; &amp;board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;bool&gt; &gt; row (9, vector&lt;bool&gt; (9,false));
        vector&lt;vector&lt;bool&gt; &gt; col (9, vector&lt;bool&gt; (9,false));
        vector&lt;vector&lt;bool&gt; &gt; block (9, vector&lt;bool&gt; (9,false));
        stack&lt;Node&gt; st;
        for(int i = 0; i &lt; 9; ++i) {
            for(int j = 0; j &lt; 9; ++j) {
                if(board[i][j] != &#39;.&#39;) {
                    int num = board[i][j] - &#39;1&#39;;
                    row[i][num] = true;
                    col[j][num] = true;
                    block[i / 3 * 3 + j / 3][num] = true;
                } else {
                    Node dot(i, j, i / 3 * 3 + j / 3);
                    st.push(dot);
                }
            }
        }
        
        dfs(board, row, col, block, st);
    }
    
    bool dfs(vector&lt;vector&lt;char&gt; &gt; &amp;board, vector&lt;vector&lt;bool&gt; &gt; &amp;row, vector&lt;vector&lt;bool&gt; &gt; &amp;col,
        vector&lt;vector&lt;bool&gt; &gt; &amp;block, stack&lt;Node&gt; st) {
        if(st.empty()) {
            return true;
        }
        Node cur = st.top();
        st.pop();
        int ro = cur.r;
        int co = cur.c;
        int bl = cur.b;
        for(int i = 0; i &lt; 9; ++i) {
            if(row[ro][i] || col[co][i] || block[bl][i]) {
                continue;
            }
            row[ro][i] = true;
            col[co][i] = true;
            block[bl][i] = true;
            if(dfs(board, row, col, block, st)) {
                board[ro][co] = i + &#39;1&#39;;
                return true;
            }
            row[ro][i] = false;
            col[co][i] = false;
            block[bl][i] = false;
        }
        st.push(cur);
        return false;
    }
};