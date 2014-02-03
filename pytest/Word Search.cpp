class Solution {
public:
    bool dfs(vector&lt;vector&lt;char&gt; &gt; &amp;board, string &amp;word, int dep, vector&lt;vector&lt;bool&gt; &gt; &amp;visit,
        int row, int col, int &amp;m, int &amp;n) {
        if(board[row][col] != word[dep] || visit[row][col]) {
            return false;
        }
        if(dep + 1 &gt;= word.size()) {
            return true;
        }
        visit[row][col] = true;
        if(row &lt; m - 1 &amp;&amp; dfs(board, word, dep + 1, visit, row + 1, col, m, n)) {
            return true;
        }
        if(row &gt; 0 &amp;&amp; dfs(board, word, dep + 1, visit, row - 1, col, m, n)) {
            return true;
        }
        if(col &lt; n - 1 &amp;&amp; dfs(board, word, dep + 1, visit, row, col + 1, m, n)) {
            return true;
        }
        if(col &gt; 0 &amp;&amp; dfs(board, word, dep + 1, visit, row, col - 1, m, n)) {
            return true;
        }
        visit[row][col] = false;
        return false;
    }
    
    bool exist(vector&lt;vector&lt;char&gt; &gt; &amp;board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = word.size();
        if(len == 0) {
            return true;
        }
        int m = board.size();
        if(m == 0) {
            return false;
        }
        int n = board[0].size();
        
        for(int i = 0; i &lt; m; ++i) {
            vector&lt;vector&lt;bool&gt; &gt; visit(m, vector&lt;bool&gt; (n, false));
            for(int j = 0; j &lt; n; ++j) {
                if(dfs(board, word, 0, visit, i, j, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }
};