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
    bool pathSum(TreeNode* root, int &amp;sum, int cur) {
        if(root == NULL) {
            return false;
        }
        if(root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) {
            return (root-&gt;val + cur) == sum;
        }
        return pathSum(root-&gt;left, sum, cur + root-&gt;val) || pathSum(root-&gt;right, sum, cur + root-&gt;val);
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return false;
        }
        return pathSum(root, sum, 0);
    }
};