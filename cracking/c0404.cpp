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
    vector<list<TreeNode*> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<list<TreeNode*> > ans;
		if(root == NULL) {
			return ans;
		}
		list<TreeNode*> last;
		last.push_back(root);
		ans.push_back(last);
		while(true) {
			list<TreeNode*> level;
			for (std::list<TreeNode*>::iterator it=last.begin(); it != last.end(); ++it) {
				if((*it)->left) {
					level.push_back((*it)->left);
				}
				if((*it)->right) {
					level.push_back((*it)->right);
				}
			}
			if(level.size() > 0) {
				ans.push_back(level);
			} else {
				break;
			}
			last = level;
		}
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

	vector<list<TreeNode*> > ans = s.levelOrderBottom(t1);
	printf("size = %d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i) {
		list<TreeNode*> cur = ans[i];
		for (std::list<TreeNode*>::iterator it=cur.begin(); it != cur.end(); ++it) {
			printf("cur = %d ",(*it)->val);
		}
		printf("\n");
	}
	
	return 0;
}
