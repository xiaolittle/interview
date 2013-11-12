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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
		if(root == NULL) {
			return ans;
		}
		int count = 1;
		vector<TreeNode*> last;
		last.push_back(root);
		while(count > 0) {
			int cur = 0;
			vector<TreeNode*> level;
			vector<int> curint;
			for(int i = 0; i < count; ++i) {
				curint.push_back(last[i]->val);
				if(last[i]->left != NULL) {
					level.push_back(last[i]->left);
					cur++;
				}
				if(last[i]->right != NULL) {
					level.push_back(last[i]->right);
					cur++;
				}
			}
			ans.push_back(curint);
			count = cur;
			last = level;
		}
		return ans;
    }
};