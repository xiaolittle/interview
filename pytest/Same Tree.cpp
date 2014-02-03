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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL &amp;&amp; q == NULL) {
            return true;
        } else if(p == NULL || q == NULL || p-&gt;val != q-&gt;val) {
            return false;
        }
        if(!isSameTree(p-&gt;left, q-&gt;left) || !isSameTree(p-&gt;right, q-&gt;right)) {
            return false;
        }
        return true;
    }
};