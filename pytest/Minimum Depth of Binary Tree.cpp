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
    void minDepth(TreeNode* root, int dep, int &amp;ans) {
        if(root == NULL) {
            return;
        }
        if(root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) {
            if(ans == -1) {
                ans = dep + 1;
                return;
            }
            ans = min(ans, dep + 1);
            return;
        }
        minDepth(root-&gt;left, dep + 1, ans);
        minDepth(root-&gt;right, dep + 1, ans);
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        int ans = -1;
        int dep = 0;
        minDepth(root, dep, ans);
        return ans;
    }
};