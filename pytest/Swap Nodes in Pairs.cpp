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
        if(head == NULL || head-&gt;next == NULL) {
            return head;
        }
        ListNode* before = NULL;
        ListNode* cur = head;
        ListNode* after = head-&gt;next-&gt;next;
        while(true) {
            ListNode* tail = cur-&gt;next;
            tail-&gt;next = cur;
            cur-&gt;next = after;
            if(before) {
                before-&gt;next = tail;
            } else {
                head = tail;
            }
            if(after == NULL || after-&gt;next == NULL) {
                break;
            }
            before = cur;
            cur = after;
            after = cur-&gt;next-&gt;next;
        }
        return head;
    }
};