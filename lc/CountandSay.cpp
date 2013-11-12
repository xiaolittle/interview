class Solution {
public:
	string count(string s) {
		int i = 0;
		int n = s.size();
		string ans;
		while(i < n) {
			char cur = s[i];
			int count = 1;
			int j = i + 1;
			while(j < n && cur == s[j]) {
				++j;
				++count;
			}
			stringstream sstrm;
			sstrm << count;
			ans += sstrm.str();
			ans += cur;
			i = j;
		}
		return ans;
	}

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string s = "1";
		if(n == 0) {
			return s;
		}
        for(int i = 1; i < n; ++i) {
			s = count(s);
		}
		return s;
    }
};