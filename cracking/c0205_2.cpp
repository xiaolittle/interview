#include <stdio.h>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 struct Result {
	 ListNode *list;
	 bool res;
	 Result(bool x) : res(x), list(NULL) {}
 }

 Result findPalindrome(ListNode *head, int len) {
	 if(len == 0) {
		 Result ans = Result(true);
		 return ans;
	 } else if(len == 1) {
		 Result ans = Result(true);
		 ans.list = head->next;
		 return ans;
	 } else if(len == 2) {
		 Result ans = Result(head->val == head->next->val);
		 ans.list = head->next->next;
		 return ans;
	 }

	 Result ans = findPalindrome(head->next, len - 2);
	 if(!ans.res || ans.list == NULL) {
		 return ans;
	 } else {
		 ans->res = ans.list->val == head->val;
		 ans.list = ans.list->next;
		 return ans;
	 }
 }

 bool isPalindrome(ListNode *l) {
	 int len = 0;
	 if(l == NULL || l->next == NULL) {
		 return true;
	 }
	 ListNode *cur = l;
	 while(cur != NULL) {
		 cur = cur->next;
		 len++;
	 }

	 Result ans = findPalindrome(l, len);
	 return ans.res;
 }

int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
