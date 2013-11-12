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
	int findBalance(TreeNode *root, int height, bool &flag) {
		if(!flag) {
			return height;
		}
		if(root == NULL) {
			return height;
		}
		if(root->left == NULL && root->right == NULL) {
			return height;
		}

		int leftheight = height;
		int rightheight = height;
		if(root->left) {
			leftheight = findBalance(root->left, height + 1, flag);
		}
		if(!flag) {
			return height;
		}
		if(root->right) {
			rightheight = findBalance(root->right, height + 1, flag);
		}
		if(!flag) {
			return height;
		}
		if(abs(leftheight - rightheight) > 1) {
			flag = false;
			return height;
		}
		return max(leftheight, rightheight);
	}

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = true;
		findBalance(root, 0, flag);
		return flag;
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
