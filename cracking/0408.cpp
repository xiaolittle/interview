#include <stdio.h>

/**
 * Definition for binary tree
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool isSubTree(TreeNode* t1, TreeNode *t2) {
		if(t2 == NULL) {
			return true;
		}
		return subTree(t1, t2);
	}

	bool subTree(TreeNode* t1, TreeNode *t2) {
		if(t1 == NULL) {
			return false;
		}
		if(t1->val == t2->val && isSameTree(t1, t2)) {
			return true;
		}
		return subTree(t1->left, t2) || subTree(t1->right, t2);
	}
	
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL && q == NULL) {
			return true;
		}
		if(p == NULL || q == NULL || p->val != q->val) {
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}
