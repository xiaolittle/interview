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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* before = NULL;

		ListNode* cur = head;
		if(head == NULL || head->next == NULL) {
			return head;
		}

		while(cur != NULL && cur->val < x) {
			before = cur;
			cur = cur->next;
		}

		while(cur != NULL && cur->next != NULL) {
			ListNode* tmp = cur->next;
			if(tmp->val < x) {
				if(before == NULL) {
					before = tmp;
					cur->next = tmp->next;
					before->next = head;
					head = before;
				} else {
					cur->next = tmp->next;
					tmp->next = before->next;
					before->next = tmp;
					before = before->next;
				}
			} else {
				cur = cur->next;
			}
		}
		return head;
    }
};