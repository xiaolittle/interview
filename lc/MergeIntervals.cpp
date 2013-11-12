/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 struct myclass {
	 bool operator() (Interval a, Interval b) {return (a.start < b.start);}
 } mycompare;
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), mycompare);
		int i = 0;
		int len = intervals.size();
		vector<Interval> ans;
		while(i < len) {
			if(i == len - 1) {
				ans.push_back(intervals[i]);
				break;
			}
			if(intervals[i].end < intervals[i + 1].start) {
				ans.push_back(intervals[i]);
				++i;
				continue;
			} else {
				int left = intervals[i].start;
				int j = i + 1;
				int right = intervals[i].end;
				while(j < len && intervals[j].start <= intervals[j - 1]) {
					right = max(right, intervals[j].end);
					++j;
				}
				i = j;
				Interval newInterval(left, right);
				ans.push_back(newInterval);
			}
		}
		return ans;
    }
};