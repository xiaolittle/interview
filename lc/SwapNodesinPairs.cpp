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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* first = head;
		if(head == NULL) {
			return head;
		}
		ListNode* second = head->next;
		ListNode* before = NULL;
		ListNode* after = NULL;
		while(true) {
			if(second == NULL) {
				break;
			}
			after = second->next;
			if(before == NULL) {
				head = second;
			} else {
				before->next = second;
			}
			second->next = first;
			first->next = after;
			before = first;
			first = after;
			if(first == NULL) {
				break;
			}
			second = first->next;
		}
		return head;
    }
};