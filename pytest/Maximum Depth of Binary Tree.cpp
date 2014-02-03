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
    void maxDepth(TreeNode *root, int dep, int &amp;maxi) {
        if(root == NULL) {
            maxi = max(maxi, dep);
            return;
        }
        maxDepth(root-&gt;left, dep + 1, maxi);
        maxDepth(root-&gt;right, dep + 1, maxi);
    }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        int maxi = 0;
        maxDepth(root, 0, maxi);
        return maxi;
    }
};