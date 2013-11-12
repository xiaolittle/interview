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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* head = NULL;
		ListNode* cur = NULL;
		while(l1 != NULL || l2 != NULL) {
			if(l1 != NULL && l2 != NULL) {
				if(l1->val < l2->val) {
					if(head == NULL) {
						head = l1;
						cur = head;
					} else {
						cur->next = l1;
						cur = cur->next;
					}
					l1 = l1->next;
				} else {
					if(head == NULL) {
						head = l2;
						cur = head;
					} else {
						cur->next = l2;
						cur = cur->next;
					}
					l2 = l2->next;
				}
			} else if(l1 != NULL){
				if(head == NULL) {
						head = l1;
						cur = head;
					} else {
						cur->next = l1;
						cur = cur->next;
					}
				l1 = l1->next;
			} else {
				if(head == NULL) {
						head = l2;
						cur = head;
					} else {
						cur->next = l2;
						cur = cur->next;
					}
				l2 = l2->next;
			}
		}

		return head;
    }
};