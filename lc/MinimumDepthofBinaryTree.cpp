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
	void findTreeDep(int &min, int dep, TreeNode *root) {
		if(root->left == NULL && root->right == NULL) {
			if(min == -1) {
				min = dep;
			} else if(dep < min) {
				min = dep;
			}
			return;
		}
		if(root->left) {
			findTreeDep(min, dep + 1, root->left);
		}
		if(root->right) {
			findTreeDep(min, dep + 1, root->right);
		}
	}

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = 0;
		if(root == NULL) {
			return min;
		}
		min = -1;
		int cur = 1;
		findTreeDep(min, cur, root);
		return min;
    }
};