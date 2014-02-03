/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return;
        }
        TreeLinkNode* first = root;
        while(first) {
            TreeLinkNode* nextfirst = NULL;
            TreeLinkNode* cur = first;
            TreeLinkNode* nextLevel = NULL;
            while(cur) {
                if(cur-&gt;left) {
                    if(nextfirst == NULL) {
                        nextfirst = cur-&gt;left;
                    }
                    if(nextLevel) {
                        nextLevel-&gt;next = cur-&gt;left;
                    }
                    nextLevel = cur-&gt;left;
                }
                if(cur-&gt;right) {
                    if(nextfirst == NULL) {
                        nextfirst = cur-&gt;right;
                    }
                    if(nextLevel) {
                        nextLevel-&gt;next = cur-&gt;right;
                    }
                    nextLevel = cur-&gt;right;
                }
                cur = cur-&gt;next;
            }
            first = nextfirst;
        }
    }
};