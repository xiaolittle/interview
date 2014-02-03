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
    TreeNode* buildTree(vector&lt;int&gt; &amp;inorder, vector&lt;int&gt; &amp;postorder, int low, int high, int postLow, int postHigh) {
        if(low &gt; high) {
            return NULL;
        }
        TreeNode* cur = new TreeNode(postorder[postHigh]);
        if(low == high) {
            return cur;
        }
        int mid;
        for(mid = low; inorder[mid] != postorder[postHigh]; ++mid);
        int len = mid - low;
        cur-&gt;left = buildTree(inorder, postorder, low, mid - 1, postLow, postLow + len - 1);
        cur-&gt;right = buildTree(inorder, postorder, mid + 1, high, postLow + len, postHigh - 1);
        return cur;
    }
    TreeNode *buildTree(vector&lt;int&gt; &amp;inorder, vector&lt;int&gt; &amp;postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() == 0) {
            return NULL;
        }
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};