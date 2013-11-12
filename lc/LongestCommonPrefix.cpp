class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
		string ans;
		if(n == 0) {
			return ans;
		} else if(n == 1) {
			return strs[0];
		}
		int i,cur = 0;
		while(true) {
			i = 1;
			while(i < n) {
				if(strs[i][cur] == 0 || strs[i][cur] != strs[0][cur]) {
					break;
				}
				++i;
			}
			if(i != n) {
				break;
			}
			ans = strs[0].substr(0, cur + 1);
			++cur;
		}
		return ans;
    }
};