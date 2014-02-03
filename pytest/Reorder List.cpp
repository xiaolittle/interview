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
    void reverseList(ListNode* &amp;head) {
        if(!head) {
            return;
        }
        ListNode* rest = head-&gt;next;
        if(!rest) {
            return;
        }
        reverseList(rest);
        head-&gt;next-&gt;next = head;
        head-&gt;next = NULL;
        head = rest;
    }
    
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head-&gt;next == NULL) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            if(fast) {
                fast = fast-&gt;next;
            }
            if(fast) {
                fast = fast-&gt;next;
            }
            if(fast) {
                slow = slow-&gt;next;
            }
        }
        ListNode* newhead = slow-&gt;next;
        slow-&gt;next = NULL;
        reverseList(newhead);
        ListNode* p = head;
        while(newhead) {
            ListNode* tmp = p-&gt;next;
            p-&gt;next = newhead;
            p = tmp;
            ListNode* tmpnew = newhead-&gt;next;
            newhead-&gt;next = p;
            newhead = tmpnew;
        }
        return;
    }
};