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
    bool figurePathSum(TreeNode *root, int &num, int cur) {
		if(root == NULL) {
			return false;
		}
		if(root->left == NULL && root->right == NULL) {
			if(cur + root->val == num) {
				return true;
			} 
			return false;
		}
		return figurePathSum(root->left, num, cur + root->val) || figurePathSum(root->right, num, cur + root->val);
	}

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) {
			return false;
		}
        return figurePathSum(root, sum, 0);
    }
};