/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct myclass {
        bool operator() (Interval a, Interval b) {
            if(a.start == b.start) {
                return a.end &lt; b.end;
            } else {
                return a.start &lt; b.start;
            }
        }
    } mycompare;
    
    vector&lt;Interval&gt; merge(vector&lt;Interval&gt; &amp;intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), mycompare);
        int n = intervals.size();
        if(n &lt; 1) {
            return intervals;
        }
        vector&lt;Interval&gt; ans;
        int i = 0;
        while(i &lt; n) {
            int l = intervals[i].start;
            int r = intervals[i].end;
            while(i &lt; n - 1 &amp;&amp; intervals[i + 1].start &lt;= r) {
                r = max(r, intervals[i + 1].end);
                ++i;
            }
            Interval cur(l, r);
            ans.push_back(cur);
            ++i;
        }
        return ans;
    }
};