class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<bool> > row (9, vector<bool> (9, false));
		vector<vector<bool> > col (9, vector<bool> (9, false));
		vector<vector<bool> > block (9, vector<bool> (9, false));

		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				if(board[i][j] != '.') {
					int tmp = board[i][j] - '1';
					if(row[i][tmp] || col[j][tmp] || block[i / 3 * 3 + j / 3][tmp]) {
						return false;
					}
					row[i][tmp] = true;
					col[j][tmp] = true;
					block[i / 3 * 3 + j / 3][tmp] = true;
				}
			}
		}
		return true;
    }
};