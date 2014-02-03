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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head-&gt;next == NULL) {
            return NULL;
        }
        ListNode *one = head-&gt;next;
        ListNode *two = head-&gt;next-&gt;next;
        while(two &amp;&amp; one != two) {
            one = one-&gt;next;
            if(two-&gt;next == NULL) {
                return NULL;
            }
            two = two-&gt;next-&gt;next;
        }
        if(two == NULL) {
            return NULL;
        }
        
        one = head;
        while(one != two) {
            one = one-&gt;next;
            two = two-&gt;next;
        }
        return one;
        
        
    }
};