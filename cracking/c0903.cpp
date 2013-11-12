#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
	public:
	int count;
	Solution() : count(0) {}
	Solution(int i) : count(i) {}

	void recursiveGet(int low, int high, vector<int> &A, vector<int> &ans, int len) {
		if(low < 0 || high >= len || low > high) {
			return;
		}
		int mid = low + (high - low) / 2;
		++count;
		if(A[mid] == mid) {
			ans.push_back(mid);
			recursiveGet(low, mid - 1, A, ans, len);
			recursiveGet(mid + 1, high, A, ans, len);
		} else if(A[mid] < mid) {
			recursiveGet(low, A[mid], A, ans, len);
			recursiveGet(mid + 1, high, A, ans, len);
		} else {
			recursiveGet(low, mid - 1, A, ans, len);
			recursiveGet(A[mid], high, A, ans, len);
		}
	}

	vector<int> getMagic(vector<int> &array) {
		int len = array.size();
		int low = 0;
		int high = len - 1;
		vector<int> ans;
		recursiveGet(low, high, array, ans, len);

		return ans;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> a;
	a.push_back(-10);
	a.push_back(-5);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(7);
	a.push_back(9);
	a.push_back(12);
	a.push_back(13);

	vector<int> ans = s.getMagic(a);
	for(int i = 0; i < ans.size(); ++i) {
		printf("%d\n",ans[i]);
	}
	printf("count = %d\n",s.count);
	
	return 0;
}
