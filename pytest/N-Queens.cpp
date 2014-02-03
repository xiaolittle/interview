class Solution {
public:
    vector&lt;string&gt; getSolution(int n, vector&lt;int&gt; &amp;q) {
        vector&lt;string&gt; cur;
        for(int i = 0; i &lt; n; ++i) {
            int x = 0;
            string line;
            while(x &lt; q[i]) {
                ++x;
                line += &#39;.&#39;;
            }
            line += &#39;Q&#39;;
            ++x;
            while(x &lt; n) {
                ++x;
                line += &#39;.&#39;;
            }
            cur.push_back(line);
        }
        return cur;
    }
    void getCombination(int n, vector&lt;int&gt; &amp;q, int dep, vector&lt;bool&gt; &amp;diag0, vector&lt;bool&gt; &amp;diag1, 
        vector&lt;vector&lt;string&gt; &gt; &amp;ans) {
        if(dep == n) {
            ans.push_back(getSolution(n, q));
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
    
    vector&lt;vector&lt;string&gt; &gt; solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;string&gt; &gt; ans;
        if(n == 0) {
            return ans;
        }
        vector&lt;int&gt; q(n);
        for(int i = 0; i &lt; n; ++i) {
            q[i] = i;
        }
        vector&lt;bool&gt; diag0(n * 2 - 1, false);
        vector&lt;bool&gt; diag1(n * 2 - 1, false);
        getCombination(n, q, 0, diag0, diag1, ans);
    }
};