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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<Interval> ans;
		int len = intervals.size();
		if(len == 0) {
			ans.push_back(newInterval);
			return ans;
		}
        if(newInterval.end < intervals[0].start) {
			ans.push_back(newInterval);
			for(int i = 0; i < len; ++i) {
				ans.push_back(intervals[i]);
			}
		} else if(newInterval.start > intervals[len - 1].end) {
			ans = intervals;
			ans.push_back(newInterval);
		} else {
			int first = 0;
			while(newInterval.start > intervals[first].end) {
				++first;
			}
			int second = first;
			while(second < len && newInterval.end >= intervals[second].start) {
				++second;
			}
			for(int i = 0; i < first; ++i) {
				ans.push_back(intervals[i]);
			}
			Interval merge(min(intervals[first].start, newInterval.start), max(intervals[second - 1].end, newInterval.end));
			ans.push_back(merge);
			for(int i = second; i < len; ++i) {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
    }
};