#include <stdio.h>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode *parent;
     TreeNode(int x) : val(x), parend(NULL), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* findnext(TreeNode* cur) {
		if(cur == NULL) {
			return NULL;
		}
		if(cur->right) {
			TreeNode* right = cur->right;
			while(right->left) {
				right = right->left;
			}
			return right;
		}
		while(true) {
			TreeNode* parent = cur->parent;
			if(parent == NULL) {
				return NULL;
			}
			if(cur == parent->left) {
				return parent;
			}
			cur = parent;
		}
	}

};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
