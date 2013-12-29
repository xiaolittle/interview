void inorderWithParentNode2(TreeNode* root) {
    TreeNode* cur = root;
    TreeNode* prev = NULL;
    TreeNode* next = NULL;
    while(cur) {
        if(prev == NULL || (prev != cur->left && prev != cur->right)) {
            if(cur->left) {
                next = cur->left;
            } else {
                visit(cur);
                if(cur->right) {
                    next = cur->right;
                } else {
                    next = cur->parent;
                }
            }
        } else if(prev == cur->left) {
            visit(cur);
            if(cur->right) {
                next = cur->right;
            } else {
                next = cur->parent;
            }
        } else {
            next = cur->parent;
        }
        prev = cur;
        cur = next;
    }
}

void inorderWithParentNode(TreeNode* root) {
    TreeNode* cur = root;
    TreeNode* pre = NULL;
    while(cur) {
        if(cur->left) {
            if(pre == NULL || pre != cur->left) {
                pre = cur;
                cur = cur->left;
            } else if(pre == cur->right) {
                pre = cur;
                cur = cur->parent;
            } else {
                visit(cur);
                pre = cur;
                if(cur->right) {
                    cur = cur->right;
                } else {
                    cur = cur->parent;
                }
            }
        } else {
            visit(cur);
            pre = cur;
            if(cur->right) {
                cur = cur->right;
            } else {
                cur = cur->parent;
            }
        }
    }
}
