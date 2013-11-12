#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 1) {
			return "1";
		}
		vector<int> fac(n);
		fac[0] = 1;
		for(int i = 1; i < n; ++i) {
			fac[i] = i * fac[i - 1];
		}
		vector<int> num(n);
		for(int i = 0; i < n; ++i) {
			num[i] = i + 1;
		}
		string ans;
		while(true) {
			int len = num.size();
			if(len <= 0) {
				break;
			}
			int cur = 0;
			int i = 0;
			while(cur < k) {
				cur += fac[len - 1];
				++i;
			}
			--i;
			cur -= fac[len - 1];
			ans += num[i] + '0';
			int j,pos;
			for(j = 0,pos = 0; j < len; ++j) {
				if(num[i] != num[j]) {
					num[pos++] = num[j];
				}
			}
			num.pop_back();
			k -= cur;
		}

		return ans;
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	Solution a;
	string x = a.getPermutation(5,37);
	printf("%s\n",x.c_str());
	return 0;
}