class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
		if(n <= 1) {
			return n;
		}
		map<char, int> mp;
		int begin = 0;
		int end = 1;
		int maxi = 1;
		mp[s[0]] = 1;

		while(end < n) {
			if(mp.count(s[end]) <= 0) {
				mp[s[end]] = 1;
				++end;
			} else {
				if((end - begin) > maxi) {
					maxi = end - begin;
				}
				while(begin < end && s[begin] != s[end]) {
					mp.erase(s[begin]);
					++begin;
				}
				if(begin < end && s[begin] == s[end]) {
					++begin;
					++end;
				}
			}
		}

		if((end - begin) > maxi) {
			maxi = end - begin;
		}

		return maxi;

    }
};