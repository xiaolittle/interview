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
	void findTreeDep(int &max, int dep, TreeNode *root) {
		if(root->left == NULL && root->right) {
			if(dep > max) {
				max = dep;
			}
			return;
		}
		if(root->left) {
			findTreeDep(max, dep + 1, root->left);
		}
		if(root->right) {
			findTreeDep(max, dep + 1, root->right);
		}
	}

    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
		if(root == NULL) {
			return max;
		}
		int cur = 1;
		findTreeDep(max, cur, root);
		return max;
    }
};