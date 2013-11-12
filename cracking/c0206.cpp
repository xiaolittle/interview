#include <stdio.h>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* findLoopStart(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	if(head== NULL || head->next == NULL) {
		return NULL;
	}

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow) {
			break;
		}
	}
	if(fast == NULL || fast->next == NULL) {
		return NULL;
	}
	slow = head;
	while(fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
