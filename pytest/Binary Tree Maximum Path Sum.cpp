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
    int maxPathSum(TreeNode* root, int &amp;maxVal) {
        if(root == NULL) {
            return 0;
        }
        if(root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) {
            maxVal = max(maxVal, root-&gt;val);
            return root-&gt;val;
        }
        int leftval = maxPathSum(root-&gt;left, maxVal);
        int rightval = maxPathSum(root-&gt;right, maxVal);
        int curval = root-&gt;val;
        if(leftval &gt; 0) {
            curval += leftval;
        }
        if(rightval &gt; 0) {
            curval += rightval;
        }
        maxVal = max(maxVal, curval);
        return max(root-&gt;val, max(root-&gt;val + leftval, root-&gt;val + rightval));
    }
    
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        int maxVal = root-&gt;val;
        maxPathSum(root, maxVal);
        return maxVal;
    }
};