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
		int val = postorder[poStart + len - 1];
		int pos = nodePos[val];
		TreeNode* root = new TreeNode(val);
		int leftLen = pos - inStart;
		root->left = buildTree(inorder, inStart, postorder, poStart, leftLen, nodePos);
		root->right = buildTree(inorder, pos + 1, postorder, poStart + leftLen, len - leftLen - 1, nodePos);
		return root;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
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
		root = buildTree(inorder, 0, postorder, 0, len, nodePos);
		return root;
    }
};