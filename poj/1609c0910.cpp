#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
	int wid;
	int len;
	Box(int x, int y) : wid(x), len(y) {}

	bool operator< (const Box &b) const { 
		if(wid == b.wid) return len < b.len;
		else return wid < b.wid; 
	}
		//return wid < b.wid; }

//	void printSelf() {
//		printf("wid = %d, len = %d\n",wid, len);
//	}
};

int getMaxHeight(vector<Box> ori, const int &n) {
	sort(ori.begin(), ori.end());
//	int ans = 0;
//	if(n == 0) {
//		return ans;
//	}

	vector<int> dp(n, 0);
	//vector<int> prev(n, -1);

	int total = 0;
//	int maxindex = -1;
	for(int i = 0; i < n; ++i) {
		if(i == 0) {
			dp[i] = 1;
		} else {
			int curmax = 0;
//			for(int j = 0; j < i; ++j) {
			for(int j = i - 1; j >= 0; --j) {
				if(ori[i].wid >= ori[j].wid && ori[i].len >= ori[j].len) {
					if(dp[j] > curmax) {
						curmax = dp[j];
						//prev[i] = j;
					}
				}
			}
			dp[i] = curmax + 1;
		}

		if(dp[i] > total) {
			total = dp[i];
			//maxindex = i;
		}
	}

//	while(maxindex != -1) {
//		//ans.push_back(ori[maxindex]);
//		maxindex = prev[maxindex];
//	}
	return total;
}


int main(int argc, char *argv[])
{
//	vector<Box> ori;
//	Box a(1, 4, 1);
//	ori.push_back(a);
//	Box b(5, 5, 2);
//	ori.push_back(b);
//	Box c(9, 5, 8);
//	ori.push_back(c);
//	Box d(2, 2, 4);
//	ori.push_back(d);
//	Box e(6, 8, 5);
//	ori.push_back(e);

//	vector<Box> ans = getMaxHeight(ori);
//	for(int i = 0; i < ans.size(); ++i) {
//		ans[i].printSelf();
//	}
	while(true) {
		int n;
		scanf("%d",&n);
		if(n == 0) {
			break;
		}
		vector<Box> ori;
		for(int i = 0; i < n; ++i) {
			int x,y;
			scanf("%d%d", &x, &y);
			ori.push_back(Box(x, y));
		}
		int ans = getMaxHeight(ori, n);
		printf("%d\n",ans);
	}
	printf("*\n");

	return 0;
}
