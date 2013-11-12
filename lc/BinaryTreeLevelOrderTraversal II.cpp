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
	void bfs(vector<vector<int> > &ans, vector<TreeNode*> last) {
		if(last.size() <= 0) {
			return;
		}
		vector<TreeNode*> cur;
		vector<int> levelans;
		for(int i = 0; i < last.size(); ++i) {
			levelans.push_back(last[i]->val);
			if(last[i]->left) {
				cur.push_back(last[i]->left);
			}
			if(last[i]->right) {
				cur.push_back(last[i]->right);
			}
		}
		bfs(ans, cur);
		ans.push_back(levelans);
	}

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
		if(root == NULL) {
			return ans;
		}
		vector<TreeNode*> last;
		last.push_back(root);
		bfs(ans, last);
		return ans;
    }
};