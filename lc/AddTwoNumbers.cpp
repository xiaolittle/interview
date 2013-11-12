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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
		ListNode *head = NULL;
		ListNode *last = head;
		while(l1 || l2 || carry) {
			int sum = 0;
			if(l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			if(l2) {
				sum += l2->val;
				l2 = l2->next;
			}
			sum += carry;
			ListNode *node = new ListNode(sum % 10);
			if(head == NULL) {
				head = node;
				last = head;
			} else {
				last->next = node;
				last = node;
			}
			carry = sum / 10;
		}

		return head;
    }
}; 