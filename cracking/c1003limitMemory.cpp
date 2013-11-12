#include <stdio.h>

const int bitsize = 1048576;
const int blocknum = 4096;

int bitfield[bitsize / 32];
int block[blocknum];

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
			block[inum / bitsize]++;
		}
	} else {
		 cout << "File can't open" << endl;
	}
	fin.close();

	for(int i = 0; i < blocknum; ++i) {
		if(block[i] < bitsize) {
			starting = i * bitsize;
			break;
		}
	}

	fin.open("dat.txt");
	if (fin.good())
	{
		while (!fin.eof())
		{
			fin >> inum;
			cout << inum << endl;
			if(inum >= starting && inum < starting + bitsize) {
				bitfield[(inum - starting) / 32] |= 1 << ((inum - starting) % 32);
			}
		}
	} else {
		 cout << "File can't open" << endl;
	}
	fin.close();

	for(int i = 0; i < bitsize / 32; ++i) {
		for(int j = 0; j < 32; ++j) {
			if(bitfield[i] & (1 << j) == 0) {
				printf("missing int = %d\n",starting + i * 32 + j);
				break;
			}
		}
	}

}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
