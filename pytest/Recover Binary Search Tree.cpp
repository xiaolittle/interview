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
    void recoverTree(TreeNode* root, TreeNode* &amp;leftnode, TreeNode* &amp;rightnode, TreeNode* &amp;last) {
        if(root == NULL) {
            return;
        }
        if(root-&gt;left) {
            recoverTree(root-&gt;left, leftnode, rightnode, last);
        }
        if(last != NULL) {
            if(last-&gt;val &gt; root-&gt;val) {
                if(leftnode == NULL) {
                    leftnode = last;
                    rightnode = root;
                } else {
                    rightnode = root;
                    return;
                }
            }
        }
        last = root;
        if(root-&gt;right) {
            recoverTree(root-&gt;right, leftnode, rightnode, last);
        }
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return;
        }
        TreeNode* leftnode = NULL;
        TreeNode* rightnode = NULL;
        TreeNode* last = NULL;
        recoverTree(root, leftnode, rightnode, last);
        if(leftnode &amp;&amp; rightnode) {
            int tmp = leftnode-&gt;val;
            leftnode-&gt;val = rightnode-&gt;val;
            rightnode-&gt;val = tmp;
        }
    }
};