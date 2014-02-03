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
        if(head == NULL || head-&gt;next == NULL || m == n) {
            return head;
        }
        ListNode* before = NULL;
        ListNode* tail = head;
        int i = 1;
        while(i &lt; m) {
            before = tail;
            tail = tail-&gt;next;
            ++i;
        }
        ListNode* afterhead = tail;
        while(i &lt; n) {
            ListNode* curlast = tail-&gt;next-&gt;next;
            ListNode* cur = tail-&gt;next;
            if(before) {
                cur-&gt;next = before-&gt;next;
                before-&gt;next = cur;
                tail-&gt;next = curlast;
            } else {
                cur-&gt;next = afterhead;
                tail-&gt;next = curlast;
                afterhead = cur;
            }
            ++i;
        }
        if(before) {
            return head;
        } else {
            return afterhead;
        }
    }
};