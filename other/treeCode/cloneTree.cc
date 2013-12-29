#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
TreeNode* cloneTree(TreeNode* root) {
//    if(root == NULL) 
//        return NULL;
//    }
    queue<TreeNode* > old;
    queue<TreeNode* > ne;
    old.push(root);
    TreeNode* newroot = new TreeNode(root->val);
    ne.push(newroot);
    int lastnum = 1;
    int curnum = 0;
    while(!old.empty()) {
        curnum = 0;
        while(lastnum > 0) {
            TreeNode* cur = old.front();
            if(cur->left) {
                curnum++;
                TreeNode* tmp = new TreeNode(cur->left->val);
                ne.front()->left = tmp;
                old.push(cur->left);
                ne.push(tmp);
            }
            if(cur->right) {
                curnum++;
                TreeNode* tmp = new TreeNode(cur->right->val);
                ne.front()->right = tmp;
                old.push(cur->right);
                ne.push(tmp);
            }
            old.pop();
            ne.pop();
            --lastnum;
        }
        lastnum = curnum;
    }
    return newroot;
}

void preorderTravel(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    printf("%d\n", root->val);
    preorderTravel(root->left);
    preorderTravel(root->right);
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

    TreeNode* newTree = s.cloneTree(t1);
    s.preorderTravel(newTree);
    
    return 0;
}
