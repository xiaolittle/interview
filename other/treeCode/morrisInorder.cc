void morrisInOrder(TreeNode* root) {
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    while(cur) {
        if(cur->left) {
            pre = cur->left;
            while(pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if(pre->right) {
                visit(cur);
                cur = cur->right;
                pre->right = NULL;
            } else {
                pre->right = cur;
                cur = cur->left;
            }
        } else {
            visit(cur);
            cur = cur->right;
        }
    }
}
