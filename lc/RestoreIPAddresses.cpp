#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
	bool isValid(string str) {
		if(str.size() == 0 || str.size() > 3) {
			return false;
		}
		int len = str.size();
		if(len == 1) {
			if(str[0] >= '0' && str[0] <= '9')
				return true;
			return false;
		} else if(str[0] == '0') {
			return false;
		} else if(len < 3 || (str[0] == '1')){
			return true;
		} else if(str[0] >= '3'){
			return false;
		} else {
			if((str[1] < '5' && str[1] >= '0') || (str[1] == '5' && str[2] <= '5' && str[2] >= '0')) {
				return true;
			}
			return false;
		}

	}

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
		vector<string> ans;
//		bool flag = true;
		for(int i = 0; i < 3 && i < n; ++i) {
//			flag = true;
			if(!isValid(s.substr(0, i + 1))) {
				break;
//				curstr += s.substr(0, i + 1);
//				curstr += '.';
			}
			for(int j = i + 1; j < i + 4 && j < n; ++j) {
				if(!isValid(s.substr(i + 1, j - i))) {
	//				flag = false;
					break;
				}
//				curstr += s.substr(i + 1, j - i);
//				curstr += '.';
				for(int k = j + 1; k < j + 4 && k < n; ++k) {
					//printf(".......... i = %d, j = %d, k = %d\n",i,j,k);
					if(!isValid(s.substr(j + 1, k - j))) {
	//					flag = false;
						break;
					}
//					curstr += s.substr(j + 1, k - j);
//					curstr += '.';
					//printf(" i = %d, j = %d, k = %d\n",i,j,k);
					if(isValid(s.substr(k + 1))) {
						string curstr = "";
						curstr += s.substr(0, i + 1);
						curstr += '.';
						curstr += s.substr(i + 1, j - i);
						curstr += '.';
						curstr += s.substr(j + 1, k - j);
						curstr += '.';
						curstr += s.substr(k + 1);
						ans.push_back(curstr);
						//printf("%s\n",curstr.c_str());
					}
				}
			}
		}

		return ans;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	s.restoreIpAddresses("010010");
	
	return 0;
}