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
    void getSum(TreeNode* root, int &amp;sum, int cur) {
        cur *= 10;
        cur += root-&gt;val;
        if(root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) {
            sum += cur;
            return;
        }
        if(root-&gt;left) {
            getSum(root-&gt;left, sum, cur);
        }
        if(root-&gt;right) {
            getSum(root-&gt;right, sum, cur);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        if(root == NULL) {
            return sum;
        }
        getSum(root, sum, 0);
        return sum;
    }
};