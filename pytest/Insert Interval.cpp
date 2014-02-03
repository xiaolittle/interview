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
    vector&lt;Interval&gt; insert(vector&lt;Interval&gt; &amp;intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;Interval&gt; ans;
        int n = intervals.size();
        if(n == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval.end &lt; intervals[0].start) {
            ans.push_back(newInterval);
            for(int i = 0; i &lt; n; ++i) {
                ans.push_back(intervals[i]);
            }
            return ans;
        } else if(newInterval.start &gt; intervals[n - 1].end) {
            for(int i = 0; i &lt; n; ++i) {
                ans.push_back(intervals[i]);
            }
            ans.push_back(newInterval);
            return ans;
        }
        int low = 0;
        while(low &lt; n &amp;&amp; newInterval.start &gt; intervals[low].end) {
            ans.push_back(intervals[low]);
            ++low;
        }
        int high = low;
        while(high &lt; n &amp;&amp; newInterval.end &gt;= intervals[high].start) {
            ++high;
        }
        Interval mergeInterval(min(intervals[low].start, newInterval.start),
                            max(newInterval.end, intervals[high - 1].end));
        ans.push_back(mergeInterval);
        for(; high &lt; n; ++high) {
            ans.push_back(intervals[high]);
        }
    }
};