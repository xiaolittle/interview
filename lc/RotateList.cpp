/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
		ListNode* cur = head;
		if(head == NULL || k == 0) {
			return head;
		}
		int len;
		while(i < k) {
			if(cur == NULL) {
				len = i;
				cur = head;
				if(len + i < k) {
					i = 0;
					k = k % len;
					while(i < k) {
						cur = cur->next;
						++i;
					}
					break;
				}
			}
			cur = cur->next;
			++i;
		}
		ListNode* before = head;
		if(cur == NULL) {
			return head;
		}
		while(cur->next != NULL) {
			before = before->next;
			cur = cur->next;
		}
		cur->next = head;
		head = before->next;
		before->next = NULL;
		return head;
    }
};