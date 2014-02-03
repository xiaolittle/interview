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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL) {
            return l2;
        } else if(l2 == NULL) {
            return l1;
        }
        ListNode* head = NULL;
        ListNode* p = NULL;
        if(l1-&gt;val &lt; l2-&gt;val) {
            head = l1;
            p = head;
            l1 = l1-&gt;next;
        } else {
            head = l2;
            p = head;
            l2 = l2-&gt;next;
        }
        while(l1 &amp;&amp; l2) {
            if(l1-&gt;val &lt; l2-&gt;val) {
                p-&gt;next = l1;
                l1 = l1-&gt;next;
            } else {
                p-&gt;next = l2;
                l2 = l2-&gt;next;
            }
            p = p-&gt;next;
        }
        if(l1) {
            p-&gt;next = l1;
        } else if(l2) {
            p-&gt;next = l2;
        }
        return head;
    }
};