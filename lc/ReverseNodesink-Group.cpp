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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(head == NULL || head->next == NULL || k <= 1) {
			return head;
		}
        ListNode *before = NULL;
		ListNode *after = head;
		while(true) {
			int i = 1;
			while(i < k && after != NULL) {
				after = after->next;
				++i;
			}
			if(after == NULL) {
				break;
			}
			after = after->next;
			ListNode* cur;
			if(before == NULL) {
				cur = head;
			} else {
				cur = before->next;
			}
			ListNode * tmpbefore = cur;
			ListNode* midnext = cur->next;
			ListNode* curafter = after;
			while(cur != after) {
				cur->next = curafter;
				curafter = cur;
				cur = midnext;
				if(midnext != NULL) {
					midnext = midnext->next;
				}
			}
			if(before == NULL) {
				head = curafter;
			} else {
				before->next = curafter;
			}
			before = tmpbefore;
		}

		return head;
    }
};