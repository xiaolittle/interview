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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL || head->next == NULL) {
			return head;
		}
		ListNode *beforestart = NULL;
		ListNode *beforeend = NULL;
		ListNode *afterstart = NULL;
		ListNode *afterend = NULL;
		while(head) {
			ListNode *tmp = head->next;
			if(head->val < n) {
				if(beforestart == NULL) {
					beforestart = head;
					beforeend = head;
				} else {
					beforeend->next = head;
					beforeend = head;
				}
			} else {
				if(afterstart == NULL) {
					afterstart = head;
					afterend = head;
				} else {
					afterend->next = head;
					afterend = head;
				}
			}
			head = tmp;
		}
		beforeend->next = afterstart;
		return beforestart;
};

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
