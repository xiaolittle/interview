#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
	int wid;
	int len;
	int hei;
	Box(int x, int y, int z) : wid(x), len(y), hei(z) {}

	bool operator< (const Box &b) const {return (wid * len) < (b.wid * b.len); }

	void printSelf() {
		printf("wid = %d, len = %d, hei = %d\n",wid, len, hei);
	}
};

vector<Box> getMaxHeight(vector<Box> ori) {
	sort(ori.begin(), ori.end());
	int n = ori.size();
	vector<Box> ans;
	if(n == 0) {
		return ans;
	}

	vector<int> dp(n, 0);
	vector<int> prev(n, -1);

	int total = 0;
	int maxindex = -1;
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			dp[i] = ori[i].hei;
		} else {
			int curmax = 0;
			for(int j = i - 1; j >= 0; --j) {
				if(ori[i].wid > ori[j].wid && ori[i].len > ori[j].len) {
					if(dp[j] > curmax) {
						curmax = dp[j];
						prev[i] = j;
					}
				}
			}
			dp[i] = curmax + ori[i].hei;
		}

		if(dp[i] > total) {
			total = dp[i];
			maxindex = i;
		}
	}

	while(maxindex != -1) {
		ans.push_back(ori[maxindex]);
		maxindex = prev[maxindex];
	}
	return ans;
}


int main(int argc, char *argv[])
{
	vector<Box> ori;
	Box a(1, 4, 1);
	ori.push_back(a);
	Box b(5, 5, 2);
	ori.push_back(b);
	Box c(9, 5, 8);
	ori.push_back(c);
	Box d(2, 2, 4);
	ori.push_back(d);
	Box e(6, 8, 5);
	ori.push_back(e);

	vector<Box> ans = getMaxHeight(ori);
	for(int i = 0; i < ans.size(); ++i) {
		ans[i].printSelf();
	}

	return 0;
}
