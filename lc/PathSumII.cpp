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
	void figurePathSum(TreeNode* root, int &sum, int cur, vector<int> & path, vector<vector<int> > &ans) {
		if(root == NULL) {
			return;
		}
		path.push_back(root->val);
		if(root->left == NULL && root->right == NULL) {
			if(cur + root->val == sum) {
				ans.push_back(path);
			}
			path.pop_back();
			return;
		}
		figurePathSum(root->left, sum, cur + root->val, path, ans);
		figurePathSum(root->right, sum, cur + root->val, path, ans);
		path.pop_back();
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > ans;
        if(root == NULL) {
			return ans;
		}
		vector<int> path;
        figurePathSum(root, sum, 0, path, ans);

		return ans;
    }
};