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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* prev = NULL;
		TreeNode* cur = root;
		vector<int> ans;
		if(root == NULL) {
			return ans;
		}
		while(cur) {
			if(cur->left == NULL) {
				ans.push_back(cur->val);
				cur = cur->right;
			} else {
				prev = cur->left;
				while(prev->right != NULL && prev->right != cur) {
					prev = prev->right;
				}
				if(prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				} else {
					prev->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}
			}
		}

		return ans;
    }
};