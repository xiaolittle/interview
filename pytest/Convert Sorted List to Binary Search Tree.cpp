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
    TreeNode *sortListToBst(ListNode* &amp;head, int n) {
        if(n == 0) {
            return NULL;
        }
        int mid = (n - 1) / 2;
        TreeNode* leftchild = sortListToBst(head, mid);
        TreeNode* cur = new TreeNode(head-&gt;val);
        head = head-&gt;next;
        cur-&gt;left = leftchild;
        cur-&gt;right = sortListToBst(head, n - mid - 1);
        return cur;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 0;
        if(head == NULL) {
            return NULL;
        }
        ListNode* tmp = head;
        while(tmp) {
            ++n;
            tmp = tmp-&gt;next;
        }
        return sortListToBst(head, n);
    }
};