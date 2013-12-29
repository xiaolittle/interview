#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

//struct Compare {
//	bool operator() (int &x, int &y) {
//		return chase[x] < chase[b];
//	}
//};

int upper_bound(const vector<int> &arr, const vector<int> &chase, int val) {
	int low = 0;
	int high = chase.size();
	while(low < high) {
		int mid = (low + high) / 2;
		if(arr[chase[mid]] <= val) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
}

vector<int> getMaxi(const vector<int> &a) {
	int n = a.size();
	//vector<pair<int, int> > path(n, make_pair(-1, 0)); //pair<before, totallength>
	vector<int> path(n); 

	vector<int> ans;
	vector<int> chase;
	for(int i = 0; i < n; ++i) {
		int pos = upper_bound(a, chase, a[i]);
		//vector<int> cur;
		if(pos >= chase.size()) {
			if(chase.size() != 0) {
				//cur = path[chase[chase.size() - 1]];
				////path[i] = make_pair(chase[pos - 1], pos + 1);
				path[i] = chase[pos - 1];
			} else {
				//cur.push_back(i);
				//path[i] = cur;
				////path[i] = make_pair(-1, 1);
				path[i] = -1;
			}
			chase.push_back(i);
		} else {
			if(pos != 0) {
				//cur = path[chase[pos - 1]];
				////path[i] = make_pair(chase[pos - 1], pos + 1);
				path[i] = chase[pos - 1];
			} else {
				////path[i] = make_pair(-1, 1);
				path[i] = -1;
			}
			chase[pos] = i;
			//cur.push_back(i);
			//path[i] = cur;
		}

//		if(path[i].size() > ans.size()) {
//			ans = path[i];
//		}
	}

//	printf("chasesize = %d\n",chase.size());
//	for(int i = 0; i < chase.size(); ++i) {
//		printf("chase[%d] = %d,path[] = %d\n",i,chase[i],path[chase[i]].first);
//	}
	int i = chase[chase.size() - 1];
	ans.push_back(i);
	while(true) {
		if(path[i] == -1) {
			break;
		}
		//printf("before get ans = %d\n",i);
		i = path[i];
		//printf("after get ans = %d\n",i);
		ans.push_back(i);
	}

	return ans;
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
		vector<int> ans = getMaxi(a);
		//printf("%d\n",ans.size());
		if(ans.size() == 0) {
			printf("0\n");
		} else {
			int cur = a[ans[ans.size() - 1]];
			for(int j = ans.size() - 2; j >= 0; --j) {
				if(a[ans[j]] < cur) {
					while(true);
				} else {
					cur = a[ans[j]];
				}
			}

//			for(int j = 0; j < ans.size(); ++j) {
//				printf("haha = %d\n",ans[j]);
//			}
			printf("%d\n",ans.size());
		}
	}
	
	return 0;
}