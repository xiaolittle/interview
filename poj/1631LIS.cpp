#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxi(const vector<int> &a) {
	int len = a.size();
	vector<int> t;
	for(int i = 0; i < len; ++i) {
		vector<int>::iterator pos = upper_bound(t.begin(), t.end(), a[i]);

		if(pos == t.end()) {
			t.push_back(a[i]);
		} else {
			*pos = a[i];
		}
	}
	return t.size();
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	for(int i = 0; i < t; ++i) {
		int n;
		scanf("%d",&n);
		vector<int> a;
		for(int j = 0; j < n; ++j) {
			int tmp;
			scanf("%d",&tmp);
			a.push_back(tmp);
		}
		printf("%d\n",getMaxi(a));
	}
	
	return 0;
}
