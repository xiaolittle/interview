class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans;
		int n = path.size();
		int i = 0;
		if(n == 0) {
			return ans;
		}
		vector<string> dir;
		while(i < n) {
			while(i < n && path[i] == '/') {
				++i;
			}
			if(i >= n) {
				break;
			}
			if(path[i] == '.') {
				int j = i;
				while(j < n && path[j] == '.') {
					++j;
				}
				if(j >= n) {
					if(j == i + 2) {
						if(dir.size() > 0) {
							dir.pop_back();
						}
					}
					break;
				}
				if(j < n && path[j] == '/') {
					if(j == i + 2) {
						if(dir.size() > 0) {
							dir.pop_back();
						}
					}
					i = j;
				}
			}
			if(i < n && path[i] != '/') {
				int j = i;
				while(j < n && path[j] != '/') {
					++j;
				}
				dir.push_back(path.substr(i, j - i));
				i = j;
			}
		}
		for(int i = 0; i < dir.size(); ++i) {
			ans += '/';
			ans += dir[i];
		}
		if(ans.size() == 0) {
			ans = "/";
		}
		return ans;
    }
};