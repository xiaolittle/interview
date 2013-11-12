/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 //别看这个，看le2的，那个是前序遍历
class Solution {
public:
	void flatten(TreeNode* root, TreeNode* &last) {
		if(root == NULL) {
			return;
		}
		if(root->left == NULL && root->right == NULL) {
			last = root;
			return;
		}
		if(root->left) {
			flatten(root->left, last);
		}
		TreeNode* curRight = root->right;
		if(root->left) {
			root->right = root->left;
			root->left = NULL;
		}
		if(last && !last->right) {
			last->right = curRight;
		}
		if(curRight) {
			flatten(curRight, last);
		}
	}
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) {
			return;
		}
		TreeNode* last = NULL;
		flatten(root, last);
    }
};