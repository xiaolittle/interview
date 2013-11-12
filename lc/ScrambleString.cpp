class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size()) {
			return false;
		}
		if(s1 == s2) {
			return true;
		}
		string t1 = s1;
		string t2 = s2;
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if(t1 != t2) {
			return false;
		}

		int n = s1.size();
		for(int i = 1; i < n; ++i) {
			if(isScramble(s1.substr(i), s2.substr(0, n - i)) && 
				isScramble(s1.substr(0, i), s2.substr(n - i))) {
				return true;
			}
		}

		for(int i = 1; i < n; ++i) {
			if(isScramble(s1.substr(0, i), s2.substr(0, i)) && 
				isScramble(s1.substr(i), s2.substr(i))) {
				return true;
			}
		}


		return false;
    }
};