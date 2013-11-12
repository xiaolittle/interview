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
	bool isBST(TreeNode* root, int &last) {
		if(root == NULL) {
			return true;
		}
		if(!isBST(root->left, last))
			return false;
		if(last >= root->val) {
			return false;
		}
		last = root->val;
		if(!isBST(root->right, last))
			return false;
		return true;
	}

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
			return true;
		}
		int begin = -1000;
		return isBST(root, begin);
    }
};