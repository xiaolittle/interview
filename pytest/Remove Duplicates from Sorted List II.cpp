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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head-&gt;next == NULL) {
            return head;
        }
        ListNode* newhead = NULL;
        ListNode* i = head;
        ListNode* j = head;
        ListNode* before = NULL;
        while(i) {
            j = i-&gt;next;
            while(j &amp;&amp; i-&gt;val == j-&gt;val) {
                j = j-&gt;next;
            }
            if(j == i-&gt;next) {
                if(newhead == NULL) {
                    newhead = i;
                    before = i;
                } else {
                    before-&gt;next = i;
                    before = i;
                }
            }
            i = j;
        }
        if(before) {
            before-&gt;next = NULL;
        }
        return newhead;
    }
};