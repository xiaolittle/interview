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
		vector<int> ans;
		if(root == NULL) {
			return ans;
		}

		stack<TreeNode*> st;
		st.push(root);
		TreeNode* cur = root;
		while(!st.empty()) {
			while(cur != NULL && cur->left != NULL) {
				st.push(cur->left);
				cur = cur->left;
			}
			if(!st.empty()) {
				TreeNode* p = st.top();
				st.pop();
				ans.push_back(p->val);
				if(p != NULL && p->right != NULL) {
					cur = p->right;
					st.push(cur);
				}
			}
		}

		return ans;
    }
};