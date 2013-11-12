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
	void bfs(TreeNode *root, TreeNode* &last, TreeNode* &leftNode, TreeNode* &rightNode) {
		if(root == NULL) {
			return;
		}
		if(root->left) {
			bfs(root->left, last, leftNode, rightNode);
		}
		if(last && last->val > root->val) {
			if(leftNode == NULL) {
				leftNode = last;
			} 
			rightNode = root;
		}
		last = root;
		if(root->right) {
			bfs(root->right, last, leftNode, rightNode);
		}
	}

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) {
			return;
		}
        TreeNode* lastNode = NULL;
		TreeNode* leftNode = NULL;
		TreeNode* rightNode = NULL;

		bfs(root, lastNode, leftNode, rightNode);
		if(leftNode && rightNode) {
			swap(leftNode->val, rightNode->val);
		}
    }
};