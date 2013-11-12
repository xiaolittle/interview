#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printLastKOfFile(const char* filename, int k) {
	ifstream file(filename);
	string line[k];
	int size = 0;
	while(file.good()) {
		getline(file,line[size % k]);
		++size;
	}

	int start = size > k ? size % k:0;

	for(int i = 0; i < k && i < size; ++i, ++start) {
		cout << line[start % k] << endl;
	}
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	printLastKOfFile("dat.txt",10);
	return 0;
}
