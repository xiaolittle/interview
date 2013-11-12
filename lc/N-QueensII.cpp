class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<bool> opdiavisit(n * 2 - 1, false);
		vector<bool> diavisit(n * 2 - 1, false);

		int ans = 0;

		vector<int> permutation;

		for(int i = 0; i < n; ++i) {
			permutation.push_back(i);
		}
		dfs(ans, n, 0, permutation, diavisit, opdiavisit);
		return ans;
	}

	void dfs(int &ans, const int& n, int dep, vector<int> &permutation, 
		vector<bool> &diavisit, vector<bool> &opdiavisit) {

		if(dep == n) {
			ans++;
			return;
		}

		for(int i = dep; i < n; ++i) {
			int j = permutation[i];
			int dia = dep + j;
			int opdia =  j - dep + n - 1;
			if(diavisit[dia] || opdiavisit[opdia]) {
				continue;
			}
			swap(permutation[dep], permutation[i]);
			diavisit[dia] = true;
			opdiavisit[opdia] = true;
			dfs(ans, n, dep + 1, permutation, diavisit, opdiavisit);
			diavisit[dia] = false;
			opdiavisit[opdia] = false;
			swap(permutation[dep], permutation[i]);
		}
    }
};