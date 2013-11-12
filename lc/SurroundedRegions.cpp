class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = board.size();
		if(m <= 0) {
			return;
		}
		int n = board[0].size();
		if(n <= 2) {
			return;
		}

		stack<pair<int, int> > st;

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(board[i][j] == 'O' && (i == 0 || i == (m - 1) || j == 0 || j == (n - 1))) {
					board[i][j] = 'N';
					st.push(make_pair(i, j));
				}
			}
		}
		const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
		while(!st.empty()) {
			pair<int, int> cur = st.top();
			st.pop();
			for(int i = 0; i < 4; ++i) {
				int r = cur.first + dir[i][0];
				int c = cur.second + dir[i][1];
				if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O') {
					board[r][c] = 'N';
					st.push(make_pair(r, c));
				}
			}
		}

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(board[i][j] == 'N') {
					board[i][j] = 'O';
				} else if(board[i][j] == 'O') {
					board[i][j] = 'X';
				} 
			}
		}
    }
};