#include <stdio.h>

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
		int col = matrix[0].size();
		vector<bool> rowZero(row, false);
		vector<bool> colZero(col, false);

		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(matrix[i][j] == 0) {
					rowZero[i] = true;
					colZero[j] = true;
				}
			}
		}

		for(int i = 0; i < row; ++i) {
			for(int j = 0; j < col; ++j) {
				if(rowZero[i] || colZero[j]) {
					matrix[i][j] = 0;
				}
			}
		}
    }
};


int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
