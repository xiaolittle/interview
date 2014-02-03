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
    bool isSymmetric(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL &amp;&amp; t2 == NULL) {
            return true;
        }
        if(t1 == NULL || t2 == NULL || t1-&gt;val != t2-&gt;val) {
            return false;
        }
        return isSymmetric(t1-&gt;left, t2-&gt;right) &amp;&amp; isSymmetric(t1-&gt;right, t2-&gt;left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return true;
        }
        return isSymmetric(root-&gt;left, root-&gt;right);
    }
};