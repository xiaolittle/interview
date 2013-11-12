class Solution {
public:
    bool dfs(int i, int j,const vector<vector<char> > &board,const string &word, 
		vector<vector<bool> > &visit, int dep,const int &m,const int &n) {
		if(dep >= word.size()) {
			return true;
		}
		if(i < 0 || j < 0 || i >= m || j >= n
			|| visit[i][j] || word[dep] != board[i][j]) {
			return false;
		}
		visit[i][j] = true;
		if(dfs(i + 1, j , board, word, visit, dep + 1, m, n)
			||dfs(i - 1, j , board, word, visit, dep + 1, m, n)
			 || dfs(i, j - 1 , board, word, visit, dep + 1, m, n)
			 || dfs(i, j + 1, board, word, visit, dep + 1, m, n)) {
			return true;
		}
		visit[i][j] = false;
		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
		if(m == 0) {
			return false;
		}
		int n = board[0].size();
		if((m * n) < word.size()) {
			return false;
		}

		vector<vector<bool> > visit(m, vector<bool> (n, false));
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dfs(i, j, board, word, visit, 0, m, n)) {
					return true;
				}
			}
		}

		return false;
    }
};