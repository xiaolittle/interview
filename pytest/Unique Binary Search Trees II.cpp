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
    TreeNode* copyTree(TreeNode* ori, int diff) {
        if(ori == NULL) {
            return NULL;
        }
        TreeNode* root = new TreeNode(ori-&gt;val + diff);
        root-&gt;left = copyTree(ori-&gt;left, diff);
        root-&gt;right = copyTree(ori-&gt;right, diff);
        return root;
    }

    vector&lt;TreeNode *&gt; generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector&lt;vector&lt;TreeNode *&gt; &gt; trees(n + 1);
        trees[0].push_back(NULL);
        if (n == 0) {
          return trees[0];
        }
        trees[1].push_back(new TreeNode(1));
        
        for(int i = 2; i &lt;= n; ++i) {
            vector&lt;TreeNode* &gt; curlevel;
            for(int j = 1; j &lt;= i; ++j) {
                for(int l = 0; l &lt; trees[j - 1].size(); ++l) {
                    for(int r = 0; r &lt; trees[i - j].size(); ++r) {
                        TreeNode* cur = new TreeNode(j);
                        cur-&gt;left = copyTree(trees[j - 1][l], 0);
                        cur-&gt;right = copyTree(trees[i - j][r], j);
                        curlevel.push_back(cur);
                    }
                }
            }
            trees[i] = curlevel;
        }
        
        return trees[n];
    }
};