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
    void reverseList(ListNode* &head) {
        if(!head) {
            return;
        }
        ListNode* rest = head->next;
        if(!rest) {
            return;
        }
        reverseList(rest);
        head->next->next = head;
        head->next = NULL;
        head = rest;
    }
    
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            if(fast) {
                fast = fast->next;
            }
            if(fast) {
                fast = fast->next;
            }
            if(fast) {
                slow = slow->next;
            }
        }
        ListNode* newhead = slow->next;
        slow->next = NULL;
        reverseList(newhead);
        ListNode* p = head;
        while(newhead) {
            ListNode* tmp = p->next;
            p->next = newhead;
            p = tmp;
            ListNode* tmpnew = newhead->next;
            newhead->next = p;
            newhead = tmpnew;
        }
        return;
    }
};
