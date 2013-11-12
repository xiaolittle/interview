class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<string> str(nRows);

		int n = s.size();
		int i = 0;
		while(i < n) {
			int j = 0;
			while(i < n && j < nRows) {
				str[j].append(1, s[i]);
				++i;
				++j;
			}
			j = nRows - 2;
			while(i < n && j > 0) {
				str[j].append(1, s[i]);
				++i;
				--j;
			}
		}
		string ans;
		for(int i = 0; i < nRows; ++i) {
			ans += str[i];
		}
		return ans;
    }
};