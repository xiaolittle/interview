class Solution {
public:
    void getCombination(int n, vector&lt;int&gt; &amp;q, int dep, vector&lt;bool&gt; &amp;diag0, vector&lt;bool&gt; &amp;diag1, 
        int &amp;ans) {
        if(dep == n) {
            ++ans;
            return;
        }
        for(int i = dep; i &lt; n; ++i) {
            int x = dep;
            int y = q[i];
            if(diag0[x + y] || diag1[x - y + n - 1]) {
                continue;
            }
            swap(q[dep], q[i]);
            diag0[x + y] = true;
            diag1[x - y + n - 1] = true;
            getCombination(n, q, dep + 1, diag0, diag1, ans);
            swap(q[dep], q[i]);
            diag0[x + y] = false;
            diag1[x - y + n - 1] = false;
        }
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) {
            return 0;
        }
        vector&lt;int&gt; q(n);
        for(int i = 0; i &lt; n; ++i) {
            q[i] = i;
        }
        vector&lt;bool&gt; diag0(n * 2 - 1, false);
        vector&lt;bool&gt; diag1(n * 2 - 1, false);
        int ans = 0;
        getCombination(n, q, 0, diag0, diag1, ans);
        return ans;
    }
};