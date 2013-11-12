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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
//		if(head->next == NULL && n == 1) {
//			return NULL;
//		}
        ListNode *first = head;
		ListNode *second = head;
		for(int i = 0; i < n; ++i) {
			second = second->next;
		}
		if(second == NULL) {
			head = head->next;
			return head;
		}
		while(second->next !=NULL) {
			first = first->next;
			second = second->next;
		}
		first->next = first->next->next;

		return head;
    }
};