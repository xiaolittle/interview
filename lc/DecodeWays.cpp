class Solution {
public:
	int calc(string s, vector<int> &num, int dep) {
		if(num[dep] != -1) {
			return num[dep];
		}
		if(s[0] == '0') {
			num[dep] = 0;
			return 0;
		}
		if(s.size() == 1) {
			num[dep] = 1;
			return 1;
		}
		if(s.size() == 2) {
			if(s[0] >= '3' || (s[0] == '2' && s[1] > '6')) {
				num[dep] = calc(s.substr(1), num, dep + 1);
			} else {
				num[dep] = 1 + calc(s.substr(1), num, dep + 1);
			}
			return num[dep];
		} else {
			if(s[0] >= '3' || (s[0] == '2' && s[1] > '6')) {
				num[dep] = calc(s.substr(1), num, dep + 1);
			} else {
				num[dep] = calc(s.substr(1), num, dep + 1) + 
					calc(s.substr(2), num, dep + 2);
			}
			return num[dep];
		}
	}

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
		if(n <= 0) {
			return 0;
		}
		vector<int> num(n, -1);
		return calc(s, num, 0);
    }
};