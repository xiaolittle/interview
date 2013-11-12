/**
 * Definition for binary tree
 */
 #include <stdio.h>
 #include <stack>
 #include <vector>

 using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode*> st;
		vector<int> ans;
		if(root == NULL) {
			return ans;
		}
		st.push(root);
		TreeNode* cur = root;
		while(!st.empty()) {
			while(cur != NULL && cur->left != NULL) {
				st.push(cur->left);
				cur = cur->left;
			}
			if(!st.empty()) {
				TreeNode* tmp = st.top();
				st.pop();
				ans.push_back(tmp->val);
				if(tmp->right != NULL) {
					cur = tmp->right;
					st.push(cur);
				}
			}
		}

		return ans;
    }
};

int main(int argc, char *argv[])
{
	//printf("Hello, world\n");
	Solution u;
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t3 = new TreeNode(3);
	t1->left = t2;
	t3->right = t1;
	vector<int> ans = u.inorderTraversal(t3);
	for(int i = 0; i < ans.size(); ++i) {
		printf("%d\n",ans[i]);
	}

	return 0;
}
