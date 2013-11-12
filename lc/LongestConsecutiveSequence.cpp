#include <tr1/unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> hash;
    	int ans = 0;
		for(int i = 0; i < num.size(); ++i) {
			hash.insert(num[i]);
		}
		for(int i = 0; i < num.size(); ++i) {
			if(hash.find(num[i]) == hash.end()) {
				continue;
			}
			int cur = 0;
			for(int p = num[i]; hash.find(p) != hash.end(); p++) {
				hash.erase(p);
				cur++;
			}
			for(int p = num[i] - 1; hash.find(p) != hash.end(); p--) {
				hash.erase(p);
				cur++;
			}
			if(cur > ans) {
				ans = cur;
			}
		}

		return ans;
    }
};