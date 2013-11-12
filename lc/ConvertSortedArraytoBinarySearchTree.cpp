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
	TreeNode* createBST(vector<int> &num, int start, int end) {
		if(end < start) {
			return NULL;
		}
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(num[mid]);
		root->left = createBST(num, start, mid - 1);
		root->right = createBST(num, mid + 1, end);
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return createBST(num, 0, num.size() - 1);
    }
};