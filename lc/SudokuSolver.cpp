class Solution {
public:
    struct Node {
		int r;
		int c;
		int b;
		Node (int x, int y, int z): r(x), c(y), b(z) {}
	};

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = board.size();
		if(n == 0) {
			return;
		}
        vector<vector<bool> > col(n, vector<bool> (n, false));
		vector<vector<bool> > row(n, vector<bool> (n, false));
		vector<vector<bool> > block(n, vector<bool> (n, false));

		vector<Node> nodes;

		int sq = sqrt(n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(board[i][j] != '.') {
					int tmp = board[i][j] - '1';
					row[i][tmp] = true;
					col[j][tmp] = true;
					block[i / sq * sq + j / sq][tmp] = true;
				} else {
					Node newNode(i, j , i / sq * sq + j / sq);
					nodes.push_back(newNode);
				}
			}
		}
		dfs(n, nodes, 0, board, row, col, block);
    }

	bool dfs(const int &n, vector<Node> &nodes, int dep, vector<vector<char> > &board,
		vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &block) {
		if(dep == nodes.size()) {
			return true;
		}

		Node cur = nodes[dep];
		int co = cur.c;
		int ro = cur.r;
		int bl = cur.b;

		for(int i = 0; i < n; ++i) {
			if(row[ro][i] || col[co][i] || block[bl][i]) {
				continue;
			}
			row[ro][i] = true;
			col[co][i] = true;
			block[bl][i] = true;
			board[ro][co] = (char)(i + '1'); 
			if(dfs(n, nodes, dep + 1, board, row, col, block)) {
				return true;
			}
			row[ro][i] = false;
			col[co][i] = false;
			block[bl][i] = false;
		}
		return false;
	}
};