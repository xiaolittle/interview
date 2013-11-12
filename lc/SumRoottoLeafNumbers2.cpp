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
	void dfs(TreeNode *root, int &sum, int cur) {
		if(root == NULL) {
			return;
		}
		int now = cur * 10 + root->val;
		if(root->left == NULL && root->right == NULL) {
			sum += now;
			return;
		} else {
			if(root->left) {
				dfs(root->left, sum, now);
			}
			if(root->right) {
				dfs(root->right, sum, now);
			}
		}
	}

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
		if(root == NULL) {
			return sum;
		}
		int cur = 0;
		dfs(root, sum, cur);
		return sum;
    }
};