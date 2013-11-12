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
		while(root) {
			TreeLinkNode* dummy = new TreeLinkNode(1);
			TreeLinkNode* head = dummy;
			while(root) {
				if(root->left) {
					dummy->next = root->left;
					dummy = dummy->next;
				}
				if(root->right) {
					dummy->next = root->right;
					dummy = dummy->next;
				}
				root = root->next;
			}
			root = head->next;
			delete head;
		}
    }
};