#include <stdio.h>
#include <vector>

using namespace std;

const int maxi = 32000;
int arr[maxi];

struct BitSet {
	vector<int> bitSet;
	BitSet(int n): bitSet(1 + (n >> 5)) {}

	bool get(int pos) {
		if(bitSet[pos >> 5] & (1 << (pos & 0x1F))) {
			return true;
		}
		return false;
	}

	void set(int pos) {
		bitSet[pos >> 5] |= 1 << (pos & 0x1F);
	}
};

void checkDuplicates() {
	BitSet bs(maxi);
	for(int i = 0; i < maxi; ++i) {
		if(bs.get(arr[i] - 1)) {
			printf("%d = %d\n",i,arr[i]);
		} else {
//			if(i > (maxi - 10)) {
//				printf("bigger than[%d] = %d,bitset[0] = %d\n",i,arr[i],bs.bitSet[(arr[i] - 1) >> 5]);
//			}
			bs.set(arr[i] - 1);
		}
	}
	printf("hahahaha\n");
}

int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < (maxi - 10); ++i) {
		arr[i] = i + 1;
	}
	for(int j = 0; i < maxi; ++i, ++j) {
		arr[i] = j * 4 + 1;
		printf("set %d = %d\n",i,arr[i]);
	}

	checkDuplicates();
	printf("eeeeeeeeeeee\n");
}
