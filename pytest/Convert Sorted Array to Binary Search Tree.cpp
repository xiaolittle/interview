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
    TreeNode* sortArrayToBst(vector&lt;int&gt; &amp;num, int low, int high) {
        if(low &gt; high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* cur = new TreeNode(num[mid]);
        cur-&gt;left = sortArrayToBst(num, low, mid - 1);
        cur-&gt;right = sortArrayToBst(num, mid + 1, high);
        return cur;
    }
    TreeNode *sortedArrayToBST(vector&lt;int&gt; &amp;num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0) {
            return NULL;
        }
        int mid = num.size() / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root-&gt;left = sortArrayToBst(num, 0, mid - 1);
        root-&gt;right = sortArrayToBst(num, mid + 1, num.size() - 1);
        return root;
    }
};