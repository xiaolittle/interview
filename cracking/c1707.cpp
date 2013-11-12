#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

string getHundredNumString(int cur) {
	string nums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string tys[9] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	string teens[9] = {"eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string str;
	if(cur >= 100) {
		str = nums[cur / 100 - 1] + " hundred";
		if(cur % 100 == 0) {
			return str;
		}
		str += " ";
		cur %= 100;
	}


	if(cur > 10 && cur < 20) {
		str += teens[cur - 11];
		return str;
	} else if(cur >= 10) {
		str += tys[cur / 10 - 1];
		cur %= 10;
		str += " ";
	}

	if(cur > 0) {
		str += nums[cur - 1];
	}

	return str;

}

string getNumString(int num) {
	string counts[4] = {"", "thousand", "million", "billion"};
	string str;
	if(num == 0) {
		str = "zero";
	} else if(num < 0) {
		str = "nagative" + getNumString(-1 * num);
	} else {
		int count = 0;
		while(num > 0) {
			if(num % 1000 != 0) {
				str = getHundredNumString(num % 1000) + " " + counts[count] + " " + str;
			}
			num /= 1000;
			count++;
		}
	}
	return str;
}

int main(int argc, char *argv[])
{
	int num = 1234567809;
	string ans = getNumString(num);
	printf("%s\n",ans.c_str());
	return 0;
}
