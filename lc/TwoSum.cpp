class Solution {
public:
	struct myclass {
		bool operator() (pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
	};
	myclass mycompare;

    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ans;
		vector<pair<int, int> > index;
		int len = numbers.size();
		if(len <= 1) {
			return ans;
		}
		for(int i = 0; i < len; ++i) {
			index.push_back(make_pair(numbers[i],i));
		}
		sort(index.begin(), index.end(), mycompare);
        int left = 0;
		int right = len - 1;
		while(left < right) {
			while(index[left].first + index[right].first < target) {
				left++;
			}
			if(index[left].first + index[right].first == target) {
				if(index[left].second < index[right].second) {
					ans.push_back(index[left].second + 1);
					ans.push_back(index[right].second + 1);
				} else {
					ans.push_back(index[right].second + 1);
					ans.push_back(index[left].second + 1);
				}
				return ans;
			}
			right--;
		}
		//return ans;
    }
};