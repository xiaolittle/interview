class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = -1;
        if((dividend &gt; 0 &amp;&amp; divisor &gt; 0) || (dividend &lt; 0 &amp;&amp; divisor &lt; 0)) {
            flag = 1;
        }
        long long divida = dividend;
        long long dividb = divisor;
        if(divida &lt; 0) {
            divida = 0 - divida;
        }
        if(dividb &lt; 0) {
            dividb = 0 - dividb;
        }
        if(divida &lt; dividb || dividb == 0) {
            return 0;
        }
        long long ori = dividb;
        int ans = 0;
        while(true) {
            int cur = 1;
            while(divida &gt;= (dividb &lt;&lt; 1)) {
                dividb &lt;&lt;= 1;
                cur &lt;&lt;= 1;
            }
            ans += cur;
            divida -= dividb;
            if(divida &lt; ori) {
                return flag * ans;
            }
            if(divida == ori) {
                return flag * (ans + 1);
            }
            dividb = ori;
        }
    }
};