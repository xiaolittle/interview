#include <stdio.h>
#include <stack>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 bool isPalindrome(ListNode *l) {
	 ListNode* slow = l;
	 ListNode* fast = l;
	 if(l == NULL || l->next == NULL) {
		 return true;
	 }

	 stack<int> st;

	 while(fast != NULL && fast->next != NULL) {
		 stack.push(slow->val);
		 slow = slow->next;
		 fast = fast->next->next;
	 }

	 if(fast != NULL) {
		 slow = slow->next;
	 }

	 while(slow != NULL) {
		 int cur = stack.top();
		 stack.pop();
		 if(cur != slow->val)
			 return false;
		 slow = slow->next;
	 }
	 return true;
 }

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
