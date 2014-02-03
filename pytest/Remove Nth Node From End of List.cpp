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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        ListNode* p = head;
        ListNode* q = head;
        if(n == 0 || head == NULL) {
            return head;
        }
        while(len &lt; n) {
            q = q-&gt;next;
            ++len;
        }
        if(q == NULL) {
            head = head-&gt;next;
            return head;
        }
        while(q-&gt;next) {
            p = p-&gt;next;
            q = q-&gt;next;
        }
        p-&gt;next = p-&gt;next-&gt;next;
        return head;
    }
};