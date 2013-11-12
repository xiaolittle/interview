#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

 // Definition for binary tree
 struct TreeNode {
     int val;
	 TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void visit(TreeNode* cur) {
		 if(cur != NULL) {
			printf("%d\n",cur->val);
		 }
	 }

    void preorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(root == NULL) {
			return;
		}

		stack<TreeNode*> st;
		st.push(root);
		TreeNode* cur = root;
		visit(root);

		while(!st.empty()) {
			while(cur != NULL && cur->left != NULL) {
				st.push(cur->left);
				cur = cur->left;
				visit(cur);
			}
			if(!st.empty()) {
				TreeNode* p = st.top();
				st.pop();
				if(p != NULL && p->right != NULL) {
					cur = p->right;
					visit(cur);
					st.push(cur);
				}
			}
		}

		return;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	TreeNode* t9 = new TreeNode(9);
	TreeNode* t7 = new TreeNode(7);
	t7->left = t9;
	TreeNode* t8 = new TreeNode(8);
	TreeNode* t6 = new TreeNode(6);
	t6->right = t7;
	TreeNode* t5 = new TreeNode(5);
	t5->left = t8;
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t3 = new TreeNode(3);
	t3->right = t6;
	TreeNode* t2 = new TreeNode(2);
	t2->left = t4;
	t2->right = t5;
	TreeNode* t1 = new TreeNode(1);
	t1->left = t2;
	t1->right = t3;

	TreeNode* t10 = new TreeNode(10);
	t8->right = t10;

	s.preorderTraversal(t1);
	
	return 0;
}
