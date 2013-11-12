#include <stdio.h>


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
        ListNode *first = head;
		ListNode *second = head->next;
		while(second != NULL) {
			while(second != NULL && first->val == second->val) {
				second = second->next;
			}
			first->next = second;
			first = second;
			if(second != NULL) {
				second = second->next;
			}
		}

		return head;
    }
};


int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
