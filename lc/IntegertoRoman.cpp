class Solution {
public:
    string intToRoman(int num) {
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

		int n = nume.size();
		string ans;
		int i = n - 1;
		while(num > 0) {
				if(nume[i].first > num) {
					--i;
				} else {
					ans += nume[i].second;
					num -= nume[i].first;
				}
		}

		return ans;
    }
};