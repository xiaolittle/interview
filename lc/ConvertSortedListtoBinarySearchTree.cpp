/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* getBST(int len, ListNode* &cur) {
		if(len <= 0) {
			return NULL;
		}
		int mid = (len - 1) / 2;
		TreeNode* left = getBST(mid, cur);
		TreeNode* root = new TreeNode(cur->val);
		cur = cur->next;
		TreeNode* right = getBST(len - 1 - mid, cur);
		root->left = left;
		root->right = right;
		return root;
	}


    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len = 0;
		ListNode* cur = head;
		while(cur != NULL) {
			++len;
			cur = cur->next;
		}
		return getBST(len, head);
    }
};