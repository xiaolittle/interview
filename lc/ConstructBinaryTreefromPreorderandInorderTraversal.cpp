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
	TreeNode *buildTree(vector<int> &inorder, int inStart, 
		vector<int> &postorder, int poStart, int len, map<int, int> &nodePos) {
		if(len <= 0) {
			return NULL;
		}
		TreeNode *root = new TreeNode(postorder[poStart]);
		int mid = nodePos[postorder[poStart]];
		int leftLen = mid - inStart;
		root->left = buildTree(inorder, inStart, postorder, poStart + 1, leftLen, nodePos);
		root->right = buildTree(inorder, mid + 1, postorder, poStart + leftLen + 1, len - leftLen - 1, nodePos);

		return root;
	}

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode* root = NULL;
        map<int, int> nodePos;
		int len = inorder.size();
		if(len == 0) {
			return root;
		}
		for(int i = 0; i < len; ++i) {
			nodePos[inorder[i]] = i;
		}
		root = buildTree(inorder, 0, preorder, 0, len, nodePos);
		return root;
    }
};