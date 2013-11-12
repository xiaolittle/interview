#include <stdio.h>

int findMissing(vector<BitInteger> array) {
	int len = BitInteger.size();
	return findMissing(array, len - 1);
}

int findMissing(vector<BitInteger> array, int col) {
	if(col < 0) {
		return 0;
	}
	vector<BitInteger> zeros;
	vector<BitInteger> ones;
	for(int i = 0; i < array.size(); ++i) {
		if(array[i].fetch(col) == 0) {
			zeros.push_back(array[i]);
		} else {
			ones.push_back(array[i]);
		}
	}
	if(zeros.size() <= ones.size()) {
		int v = findMissing(zeros, col - 1);
		return v << 1;
	} else {
		int v = findMissing(ones, col - 1);
		return (v << 1) | 1;
	}
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
