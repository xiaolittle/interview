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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         vector<vector<int> > ans;
		 if(root == NULL) {
			 return ans;
		 }
		 int count = 0;
		 vector<TreeNode*> last;
		 last.push_back(root);
		 bool re = false;
		 while(!last.empty()) {
			 vector<int> levelans;
			 int cur = 0;
			 vector<TreeNode*> levelNode;
			 for(int i = 0; i < last.size(); ++i) {
				 levelans.push_back(last[i]->val);
				 if(last[i]->left) {
					 levelNode.push_back(last[i]->left);
				 }
				 if(last[i]->right) {
					 levelNode.push_back(last[i]->right);
				 }
			 }
			 if(re) {
				 vector<int> tmp;
				 for(int i = levelans.size() - 1; i >= 0; --i) {
					 tmp.push_back(levelans[i]);
				 }
				 ans.push_back(tmp);
			 } else {
				 ans.push_back(levelans);
			 }

			 re = !re;
			 last = levelNode;
		 }
		 return ans;
    }
};