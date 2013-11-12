class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ans;
		vector<bool> visit(1 << n, false);
		int num = 0;
		visit[num] = true;
		ans.push_back(num);
		if(n == 0) {
			return ans;
		}
		int total = (1 << n);
		for(int i = 1; i < total; ++i) {
			for(int j = 0; j < n; ++j) {
				if(!visit[num ^ (1 << j)]) {
					num = num ^ (1 << j);
					visit[num] = true;
					break;
				}
			}
			ans.push_back(num);
		}

		return ans;
    }
};