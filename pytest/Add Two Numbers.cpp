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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *head = NULL;
        ListNode *cur = NULL;
        int carry = 0;
        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1-&gt;val;
                l1 = l1-&gt;next;
            }
            if(l2) {
                carry += l2-&gt;val;
                l2 = l2-&gt;next;
            }
            if(head == NULL) {
                head = new ListNode(carry % 10);
                cur = head;
            } else {
                cur-&gt;next = new ListNode(carry % 10);
                cur = cur-&gt;next;
            }
            carry /= 10;
        }
        return head;
    }
};