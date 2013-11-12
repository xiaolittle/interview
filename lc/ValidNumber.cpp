class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == NULL || *s == 0) {
			return false;
		}
		int n = strlen(s);
		if(n == 0) {
			return false;
		}
		int start = 0;
		while(start < n && s[start] == ' ') {
			++start;
		}
		int end = n - 1;
		while(end >= 0 && s[end] == ' ') {
			--end;
		}
		if(start > end) {
			return false;
		}
		if(s[start] == '-' || s[start] == '+') {
			++start;
		}
		if(start > end) {
			return false;
		}

		int epos = start;
		while(epos <= end && s[epos] != 'e') {
			++epos;
		}
		if(epos == start || epos == end) {
			return false;
		}

		bool leftdot = false;
		for(int i = start; i < epos; ++i) {
			if(s[i] == '.') {
				if(leftdot) {
					return false;
				}
				leftdot = true;
			} else {
				if(s[i] < '0' || s[i] > '9') {
					return false;
				}
			}
		}
		if((epos == (start + 1)) && leftdot) {
			return false;
		}
		if(epos >= end) {
			return true;
		}
		int after = epos + 1;
		if(s[after] == '-' || s[after] == '+') {
			++after;
		}
		if(after > end) {
			return false;
		}
		for(int i = after; i <= end; ++i) {
			if(s[i] < '0' || s[i] > '9') {
				return false;
			}
		}
		return true;
    }
};