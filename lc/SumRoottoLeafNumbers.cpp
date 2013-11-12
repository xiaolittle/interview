#include <stdio.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void getTreeSum(TreeNode *root, int cur, int &sum) {
		if(root == NULL) {
			return;
		} else if(root->left == NULL && root->right == NULL) {
			sum += cur * 10 + root->val;
			return;
		}
		int curVal = cur * 10 + root->val;
		if(root->left != NULL) {
			getTreeSum(root->left, curVal, sum);
		}
		if(root->right != NULL) {
			getTreeSum(root->right, curVal, sum);
		}
	}

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
			return 0;
		}
		int sum = 0;
		getTreeSum(root, 0, sum);
		return sum;
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
