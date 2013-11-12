#include <stdio.h>
#include <limits>
#include <fstream>
#include <iostream>

using namespace std;

int numberOfInt = numeric_limits<int>::max();
//const int len = int(numberOfInt) / 32;
const int len = 2;
int bitfield[len];

void findMissingNum() {
	ifstream fin;
	int inum;
	fin.open("dat.txt");
	if (fin.good())
	{
		while (!fin.eof())
		{
			fin >> inum;
			cout << inum << endl;
			bitfield[inum / 32] |= 1 << (inum % 32);
		}
	} else {
		 cout << "File can't open" << endl;
	}
	fin.close();
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < 32; ++j) {
			if((bitfield[i] & (1 << j)) == 0) {
				printf("missing num = %d\n",i * 32 + j);
				break;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	findMissingNum();
	return 0;
}
