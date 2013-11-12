 #include <stdio.h>
 #include <vector>
 using namespace std;
//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };





class Solution {
public:
	TreeNode* copyTree(TreeNode* oriTree, int diff) {
		if(oriTree == NULL) {
			return NULL;
		}
		if(diff == 0) {
			return oriTree;
		}
		TreeNode *root = new TreeNode(oriTree->val + diff);
		if(oriTree->left) {
			root->left = copyTree(oriTree->left, diff);
		}
		if(oriTree->right) {
			root->right = copyTree(oriTree->right, diff);
		}
		return root;
	}

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<TreeNode *> > tree(n + 1);
		tree[0].push_back(NULL);
		if(n == 0) {
			return tree[0];
		}
		tree[1].push_back(new TreeNode(1));
		for(int i = 2; i <= n; ++i) {
			for(int j = 0; j < i; ++j) {
				for(int l = 0; l < tree[j].size(); ++l) {
					for(int r = 0; r < tree[i - 1 - j].size(); ++r) {
						TreeNode* root = new TreeNode(j + 1);
						root->left = copyTree(tree[j][l], 0);
						root->right = copyTree(tree[i - 1 - j][r], j + 1);
						tree[i].push_back(root);
					}
				}
			}
		}
		return tree[n];
    }
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
