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
    vector&lt;vector&lt;int&gt; &gt; zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;int&gt; &gt; ans;
        if(root == NULL) {
            return ans;
        }
        queue&lt;TreeNode*&gt; q;
        q.push(root);
        int count = 1;
        bool flag = false;
        while(count != 0) {
            vector&lt;int&gt; level;
            int curcount = 0;
            for(int i = 0; i &lt; count; ++i) {
                TreeNode* curnode = q.front();
                q.pop();
                level.push_back(curnode-&gt;val);
                if(curnode-&gt;left) {
                    q.push(curnode-&gt;left);
                    curcount++;
                }
                if(curnode-&gt;right) {
                    q.push(curnode-&gt;right);
                    curcount++;
                }
            }
            if(flag) {
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            ans.push_back(level);
            count = curcount;
        }
        return ans;
    }
};