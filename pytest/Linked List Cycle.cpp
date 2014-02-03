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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head-&gt;next == NULL) {
            return false;
        }
        ListNode *one = head-&gt;next;
        ListNode *two = head-&gt;next-&gt;next;
        while(two &amp;&amp; one != two) {
            one = one-&gt;next;
            if(two-&gt;next == NULL) {
                return false;
            }
            two = two-&gt;next-&gt;next;
        }
        if(two == NULL) {
            return false;
        } else {
            return true;
        }
    }
};