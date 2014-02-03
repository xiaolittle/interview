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
    void getPathSum(TreeNode* root, int &amp;sum, int cur, vector&lt;vector&lt;int&gt; &gt; &amp;ans, vector&lt;int&gt; &amp;way) {
        if(root == NULL) {
            return;
        }
        if(root-&gt;left == NULL &amp;&amp; root-&gt;right == NULL) {
            if(root-&gt;val + cur == sum) {
                way.push_back(root-&gt;val);
                ans.push_back(way);
                way.pop_back();
            }
            return;
        }
        way.push_back(root-&gt;val);
        getPathSum(root-&gt;left, sum, cur + root-&gt;val, ans, way);
        getPathSum(root-&gt;right, sum, cur + root-&gt;val, ans, way);
        way.pop_back();
    }
    
    vector&lt;vector&lt;int&gt; &gt; pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; ans;
        if(root == NULL) {
            return ans;
        }
        vector&lt;int&gt; way;
        getPathSum(root, sum, 0, ans, way);
        return ans;
    }
};