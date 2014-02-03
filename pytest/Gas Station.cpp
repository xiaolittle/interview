class Solution {
public:
    int canCompleteCircuit(vector&lt;int&gt; &amp;gas, vector&lt;int&gt; &amp;cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = gas.size();
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return gas[0] &gt;= cost[0] ? 0 : -1;
        }
        vector&lt;int&gt; gap(n * 2);
        for(int i = 0; i &lt; n; ++i) {
            gap[i] = gas[i] - cost[i];
        }
        for(int i = n; i &lt; 2 * n; ++i) {
            gap[i] = gap[i - n];
        }
        
        for(int i = 0; i &lt; n;) {
            if(gap[i] &lt; 0) {
                ++i;
                continue;
            }
            int sum = gap[i];
            int j;
            for(j = i + 1; j &lt; i + n; ++j) {
                if(sum + gap[j] &gt;= 0) {
                    sum += gap[j];
                } else {
                    break;
                }
            }
            if(j == i + n) {
                return i;
            }
            i = j;
        }
        
        return -1;
    }
};