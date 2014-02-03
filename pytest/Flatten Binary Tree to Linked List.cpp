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
    void preTravel(TreeNode *root, TreeNode* &amp;last) {
        if(root == NULL) {
            return;
        }
        TreeNode* curRight = root-&gt;right;
        TreeNode* curLeft = root-&gt;left;
        if(last != NULL) {
            last-&gt;right = root;
        }
        last = root;
        root-&gt;left = NULL;
        if(curLeft) {
            preTravel(curLeft, last);
        }
        if(curRight) {
            preTravel(curRight, last);
        }
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return;
        }
        TreeNode* last = NULL;
        preTravel(root, last);
    }
};