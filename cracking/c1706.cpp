#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> findMN(vector<int> a) {
	int len = a.size();
	int i = 0;
	while((i + 1) < len && a[i] <= a[i + 1]) {
		++i;
	}
	printf("i = %d\n",i);
	if(i == len - 1) {
		return make_pair(0, 0);
	}

	int j = len - 1;
	while(j > 0 && a[j - 1] <= a[j]) {
		--j;
	}
	printf("j = %d\n",j);
	if(i >= j) {
		return make_pair(0, 0);
	}

	sort(a.begin() + i + 1, a.begin() + j - 1);
	int left = i;
	int right = j;
	while(left >= 0 && a[left] > a[i + 1]) {
		--left;
	}
	printf("left = %d\n",left);
	while(right < len && a[right] < a[j - 1]) {
		++right;
	}
	printf("right = %d\n",right);

	return make_pair(left + 1, right - 1);
}

int main(int argc, char *argv[])
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(7);
	a.push_back(10);
	a.push_back(11);
	a.push_back(7);
	a.push_back(12);
	a.push_back(6);
	a.push_back(7);
	a.push_back(16);
	a.push_back(18);
	a.push_back(19);

	pair<int, int> ans = findMN(a);
	printf("%d,%d\n",ans.first, ans.second);
	
	return 0;
}
