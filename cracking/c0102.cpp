#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

bool diffchar(string str) {
	if(str.size() > 256) {
		return false;
	}
	bool occupy[256];
	for(int i = 0; i < 256; ++i) {
		occupy[i] = false;
	}

	int len = str.size();
	for (int i = 0; i < len; ++i) {
		if(occupy[str[i]]) {
			return false;
		}
		occupy[str[i]] = true;
	}
	return true;
}
int main(int argc, char *argv[])
{
	
	return 0;
}
