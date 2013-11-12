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
	void inorderTravelTree(TreeNode *root,vector<int> &ans) {
		if(root == NULL) {
			return;
		}
		if(root->left != NULL) {
			inorderTravelTree(root->left, ans);
		}
		ans.push_back(root->val);
		if(root->right != NULL) {
			inorderTravelTree(root->right, ans);
		}
	}


    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
		inorderTravelTree(root, ans);
		return ans;
    }
};