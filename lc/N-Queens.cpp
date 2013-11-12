class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> colvisit(n, false);
		vector<bool> opdiavisit(n * 2 - 1, false);
		vector<bool> diavisit(n * 2 - 1, false);

		vector<vector<string> > ans;

		vector<int> permutation;

		for(int i = 0; i < n; ++i) {
			permutation.push_back(i);
		}
		dfs(ans, n, 0, permutation, diavisit, opdiavisit);
		return ans;
	}

	void dfs(vector<vector<string> > &ans, const int& n, int dep, vector<int> &permutation, 
		vector<bool> &diavisit, vector<bool> &opdiavisit) {

		if(dep == n) {
			getSolutation(ans, n, permutation);
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

	void getSolutation(vector<vector<string> > &ans, const int& n, vector<int> &permutation) {
		vector<string> cur;
		for(int i = 0; i < n; ++i) {
			string line = "";
			for(int j = 0; j < n; ++j) {
				if(permutation[i] == j) {
					line += 'Q';
				} else {
					line += '.';
				}
			}
			cur.push_back(line);
		}
		ans.push_back(cur);
	}
};