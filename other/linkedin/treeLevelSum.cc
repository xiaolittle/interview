#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int &ans, int dep) {
    ans += dep * root->val;
    if(root->left) {
        dfs(root->left, ans, dep + 1);
    }
    if(root->right) {
        dfs(root->right, ans, dep + 1);
    }
}

int levelTreeSum(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 0;
    dfs(root, ans, 1);
    return ans;
}

int main() {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    t1->left = t2;
    TreeNode *t3 = new TreeNode(3);
    t1->right = t3;
    TreeNode *t4 = new TreeNode(4);
    t2->left = t4;
    TreeNode *t5 = new TreeNode(5);
    t2->right = t5;
    TreeNode *t6 = new TreeNode(6);
    t5->left = t6;
    TreeNode *t7 = new TreeNode(7);
    t3->right = t7;
    int ans = levelTreeSum(t1);
    printf("%d\n",ans);
}
