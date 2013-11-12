class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
		int len = s.size();
		if(len % 2 == 1) {
			return false;
		}
		int i = 0;
		while(i < len) {
			if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
				st.push(s[i]);
			} else {
				if(st.empty()) {
					return false;
				}
				if(s[i] == ')') {
					char last = st.top();
					st.pop();
					if(last != '(') {
						return false;
					}
				} else if(s[i] == ']') {
					char last = st.top();
					st.pop();
					if(last != '[') {
						return false;
					}
				} else if(s[i] == '}') {
					char last = st.top();
					st.pop();
					if(last != '{') {
						return false;
					}
				}
			}
			++i;
		}
		if(st.empty()) {
			return true;
		} else {
			return false;
		}
    }
};