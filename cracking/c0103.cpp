#include <stdio.h>
#include <string>

using namespace std;

bool permutation(string s, string t) {
	int count[256];
	for (int i = 0; i < 256; ++i) {
		count[i] = 0;
	}
	int len = s.size();
	if(len != t.size()) {
		return false;
	}
	for (int i = 0; i < len; ++i) {
		count[static_cast<unsigned char>(s[i])]++;
	}

	for (int i = 0; i < len; ++i) {
		--count[t[i]];
		if(count[t[i]] < 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
