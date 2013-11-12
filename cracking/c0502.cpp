#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>

using namespace std;

class Solution {
	public:
	string getIntStr(int intpart) {
		string ans;
		if(intpart == 0) {
			return "0";
		}
		while(intpart) {
			if(intpart % 2 == 1) {
				ans += "1";
			} else {
				ans += "0";
			}
			intpart /= 2;
		}
		return ans;
	}

	string getDecStr(double decpart) {
		string ans;
		while(decpart > 0) {
			if(ans.size() > 32) {
				return "ERROR";
			}
			decpart *= 2;
			if(decpart >= 1.0) {
				ans += "1";
				decpart -= 1.0;
			} else {
				ans += "0";
			}
		}
		return ans;
	}

	string getDecBinaryString(string x) {
		int dotpos = x.find(".");
		int intpart = atoi(x.substr(0, dotpos).c_str());
		string decpartstr = "0" + x.substr(dotpos);
		double decpart =  atof(decpartstr.c_str());

		string intstr = getIntStr(intpart);
		string decstr = getDecStr(decpart);
		if(decstr[0] == 'E') {
			return decstr;
		} 
		if(decstr.size() == 0) {
			return intstr;
		}
		return intstr + "." + decstr;
	}
};

int main(int argc, char *argv[])
{
	Solution sl;
	char str[50];
	scanf("%s",str);
	string ans = sl.getDecBinaryString(str);

	printf("ans = %s\n",ans.c_str());
	
	return 0;
}
