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
        ListNode* i = head;
        ListNode* j = head;
        while(i) {
            while(j-&gt;next &amp;&amp; j-&gt;val == j-&gt;next-&gt;val) {
                j = j-&gt;next;
            }
            i-&gt;next = j-&gt;next;
            i = i-&gt;next;
            j = i;
        }
        return head;
    }
};