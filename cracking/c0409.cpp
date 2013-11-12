#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

//int findDepth(TreeNode* root) {
//	if(root == NULL) {
//		return 0;
//	}
//	return max(1 + findDepth(root->left), 1 + findDepth(root->right));
//}

void findSum(TreeNode* root, int sum, vector<vector<TreeNode*> > &ans, vector<TreeNode*> &curpath, int dep) {
	if(root == NULL) {
		return;
	}
	curpath.push_back(root);
	int tmp = 0;
	vector<TreeNode*> tmppath;
	for(int i = dep; i >= 0; i--) {
		tmp += curpath[i]->val;
		tmppath.push_back(curpath[i]);
		if(tmp == sum) {
			ans.push_back(tmppath);
		}
	}
	findSum(root->left, sum, ans, curpath, dep + 1);
	findSum(root->right, sum, ans, curpath, dep + 1);
	curpath.pop_back();
}

vector<vector<TreeNode*> > findSum(TreeNode* root, int sum) {
//	int dep = findDepth(root);
	vector<vector<TreeNode*> > ans;
	vector<TreeNode*> curpath;

	findSum(root, sum, ans, curpath, 0);
	return ans;
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

	vector<vector<TreeNode*> > ans = s.findSum(t1, 7);
	printf("size = %d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i) {
		vector<TreeNode*> cur = ans[i];
		for (int i = 0; i < cur.size(); ++i) {
			printf("cur = %d ",cur[i]->val);
		}
		printf("\n");
	}
	
	return 0;
}
