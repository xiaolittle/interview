class Solution {
public:
    bool isValidSudoku(vector&lt;vector&lt;char&gt; &gt; &amp;board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;bool&gt; &gt; row(9, vector&lt;bool&gt; (9, false));
        vector&lt;vector&lt;bool&gt; &gt; col(9, vector&lt;bool&gt; (9, false));
        vector&lt;vector&lt;bool&gt; &gt; block(9, vector&lt;bool&gt; (9, false));
        
        for(int i = 0; i &lt; 9; ++i) {
            for(int j = 0; j &lt; 9; ++j) {
                if(board[i][j] != &#39;.&#39;) {
                    int cur = board[i][j] - &#39;1&#39;;
                    if(row[i][cur] || col[j][cur] || block[i / 3 * 3 + j / 3][cur]) {
                        return false;
                    }
                    row[i][cur] = true;
                    col[j][cur] = true;
                    block[i / 3 * 3 + j / 3][cur] = true;
                }
            }
        }
        return true;
    }
};