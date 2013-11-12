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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = n - m;
		if(len <= 0) {
			return head;
		}
		ListNode* before = NULL;
		if(m != 1) {
			int i = 2;
			before = head;
			while(i < m) {
				before = before->next;
				++i;
			}
		}
		ListNode *cur = head;
		if(before != NULL) {
			cur = before->next;
		}
		int i = 0;
		while(i < len) {
			ListNode* curnext = cur->next;
			if(curnext != NULL) {
				cur->next = curnext->next;
				if(before == NULL) {
					curnext->next = head;
					head = curnext;
				} else {
					curnext->next = before->next;
					before->next = curnext;
				}
			} else {
				break;
			}
			++i;
		}
		return head;
    }
};