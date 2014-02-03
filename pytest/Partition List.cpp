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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head-&gt;next == NULL) {
            return head;
        }
        ListNode* before;
        ListNode* beforeend;
        ListNode* after;
        ListNode* afterend;
        after = head;
        afterend = head;
        if(after-&gt;val &gt;= x) {
            while(afterend &amp;&amp; afterend-&gt;val &gt;= x) {
                after = afterend;
                afterend = afterend-&gt;next;
            }
            if(afterend == NULL) {
                return head;
            } else {
                after-&gt;next = afterend-&gt;next;
                before = afterend;
                before-&gt;next = head;
                beforeend = before;
                afterend = after-&gt;next;
            }
        } else {
            before = head;
            beforeend = head;
            while(beforeend-&gt;next != NULL &amp;&amp; beforeend-&gt;next-&gt;val &lt; x) {
                beforeend = beforeend-&gt;next;
            }
            if(beforeend-&gt;next == NULL) {
                return head;
            }
            after = beforeend-&gt;next;
            afterend = beforeend-&gt;next;
        }
        
        while(true) {
            while(afterend &amp;&amp; afterend-&gt;val &gt;= x) {
                after = afterend;
                afterend = afterend-&gt;next;
            }
            if(afterend == NULL) {
                return before;
            } else {
                after-&gt;next = afterend-&gt;next;
                afterend-&gt;next = beforeend-&gt;next;
                beforeend-&gt;next = afterend;
                beforeend = afterend;
                afterend = after-&gt;next;
            }
        }
        return before;
    }
};