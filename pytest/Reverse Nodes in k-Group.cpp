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
        if(k &lt; 2 || head == NULL || head-&gt;next == NULL) {
            return head;
        }
        ListNode* newhead = NULL;
        ListNode* before = NULL;
        ListNode* tail = head;
        ListNode* afterhead = head;
        int i = 0;
        while(tail) {
            i = 1;
            ListNode* after = afterhead;
            while(i &lt; k &amp;&amp; after) {
                after = after-&gt;next;
                ++i;
            }
            if(after == NULL) {
                break;
            }
            after = after-&gt;next;
            i = 1;
            while(i &lt; k) {
                ListNode* cur = tail-&gt;next;
                if(before) {
                    tail-&gt;next = cur-&gt;next;
                    cur-&gt;next = before-&gt;next;
                    before-&gt;next = cur;
                    afterhead = cur;
                } else {
                    tail-&gt;next = cur-&gt;next;
                    cur-&gt;next = afterhead;
                    afterhead = cur;
                }
                ++i;
            }
            if(newhead == NULL) {
                newhead = afterhead;
            }
            before = tail;
            tail = after;
            afterhead = after;
        }
        
        if(newhead == NULL) {
            return head;
        }
        return newhead;
    }
};