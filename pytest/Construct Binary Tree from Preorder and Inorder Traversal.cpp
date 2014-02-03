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
    TreeNode *build(vector&lt;int&gt; &amp;preorder, vector&lt;int&gt; &amp;inorder, int low, int high, int preLow, int preHigh) {
        if(low &gt; high) {
            return NULL;
        }
        TreeNode* cur = new TreeNode(preorder[preLow]);
        if(low == high) {
            return cur;
        }
        int mid;
        for(mid = low; inorder[mid] != preorder[preLow]; ++mid);
        int len = mid - low;
        cur-&gt;left = build(preorder, inorder, low, mid - 1, preLow + 1, preLow + len);
        cur-&gt;right = build(preorder, inorder, mid + 1, high, preLow + len + 1, preHigh);
        return cur;
    }
    TreeNode *buildTree(vector&lt;int&gt; &amp;preorder, vector&lt;int&gt; &amp;inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.size() == 0) {
            return NULL;
        }
        return build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};