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
	int findMaxPath(int &maxi, TreeNode* root) {
		if(root == NULL) {
			return 0;
		}
		if(root->left == NULL && root->right == NULL) {
			if(root->val > maxi) {
				maxi = root->val;
			}
			return root->val;
		}
		int leftmax = findMaxPath(maxi, root->left);
		int rightmax = findMaxPath(maxi, root->right);
		maxi = max(maxi, max(root->val, max(root->val + leftmax, max(root->val + rightmax, root->val + leftmax + rightmax))));
		return max(root->val, max(root->val + leftmax, root->val + rightmax));
	}

    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxi = 0;
		if(root == NULL) {
			return maxi;
		}
		maxi = root->val;
		findMaxPath(maxi, root);
		return maxi;
    }
};