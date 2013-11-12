/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct PartialSum {
	ListNode *list = NULL;
	int carry = 0;
};

class Solution {
public:
	ListNode* padList(ListNode *l, int difflen) {
		ListNode *head = l;
		for(int i = 0; i < difflen; ++i) {
			ListNode *cur = new ListNode(0);
			cur->next = head;
			head = cur;
		}
		return head;
	}

	ListNode* insertBefore(ListNode *l, int value) {
		ListNode *cur = new ListNode(value);
		cur->next = l1;
		return cur;
	}

	PartialSum addListHelper(ListNode *l1, ListNode *l2) {
		if(l1 == NULL && l2->next == NULL) {
			PartialSum curSum;
			return curSum;
		}
		PartialSum last = addListHelper(l1->next, l2->next);

		int sum = l1->val + l2->val + last.carry;

		PartialSum curSum;
		ListNode *cur = insertBefore(last.list, sum % 10);
		curSum.list = cur;
		curSum.carry = sum / 10;

		return curSum;
	}

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int len1= 0;
		int len2= 0;
		ListNode *p1,*p2;
		p1 = l1;
		p2 = l2;
		while(p1 != NULL) {
			len1++;
			p1 = p1->next;
		}
		while(p2 != NULL) {
			len2++;
			p2 = p2->next;
		}
		if(len1 < len2) {
			l1 = padList(l1, len2 - len1);
		} else if(len1 > len2){
			l2 = padList(l2, len1 - len2);
		}

		PartialSum ans = addListHelper(l1, l2);
		if(ans.carry == 0) {
			return ans.list;
		} else {
			ListNode *result = insertBefore(ans.list, ans.carry);
			return result;
		}

    }
}; 