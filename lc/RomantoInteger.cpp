#include <vector>
#include <string>
#include <utility>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<int, string> > nume;
		nume.push_back(make_pair(1,"I"));
		nume.push_back(make_pair(4,"IV"));
		nume.push_back(make_pair(5,"V"));
		nume.push_back(make_pair(9,"IX"));
		nume.push_back(make_pair(10,"X"));
		nume.push_back(make_pair(40,"XL"));
		nume.push_back(make_pair(50,"L"));
		nume.push_back(make_pair(90,"XC"));
		nume.push_back(make_pair(100,"C"));
		nume.push_back(make_pair(400,"CD"));
		nume.push_back(make_pair(500,"D"));
		nume.push_back(make_pair(900,"CM"));
		nume.push_back(make_pair(1000,"M"));

		int num = 0;
		int n = s.size();
		if(n <= 0) {
			return num;
		}
		int cur = 0;
		int i = nume.size() - 1;
		while(cur < n) {
			if(cur + 1 < n && s.substr(cur,2) == nume[i].second) {
				num += nume[i].first;
				cur += 2;
			} else if(s.substr(cur,1) == nume[i].second) {
				num += nume[i].first;
				cur += 1;
			} else {
				//printf("--%d,cur = %d\n",i,cur);
				--i;
			}
		}
		return num;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	s.romanToInt("V");
	
	return 0;
}