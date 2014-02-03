/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBst(TreeNode *root, TreeNode* &amp;last) {
        if(root == NULL) {
            return true;
        }
        if(root-&gt;left) {
            if(!isValidBst(root-&gt;left, last)) {
                return false;
            }
        }
        if(last &amp;&amp; last-&gt;val &gt;= root-&gt;val) {
            return false;
        }
        last = root;
        return isValidBst(root-&gt;right, last);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return true;
        }
        TreeNode* last = NULL;
        return isValidBst(root, last);
    }
};