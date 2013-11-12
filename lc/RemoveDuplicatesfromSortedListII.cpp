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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *before = head;
        ListNode *first = head;
		ListNode *second = head->next;
		while(second != NULL) {
			if(first->val != second->val) {
				if(before != first) {
					before->next = first;
					before = first;
				}
				first = second;
				second = second->next;
			} else {
				while(second != NULL && first->val == second->val) {
					second = second->next;
				}
				if(head == first) {
					head = second;
					before = second;
				} else {
					before->next = second;
				}
				first = second;
				if(second != NULL) {
					second = second->next;
				}
			}
		}
		return head;
    }
};