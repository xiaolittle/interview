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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k == 0 || head == NULL || head-&gt;next == NULL) {
            return head;
        }
        int len = 0;
        ListNode* p = head;
        while(p) {
            p = p-&gt;next;
            ++len;
        }
        len = k % len;
        if(len == 0) {
            return head;
        }
        p = head;
        int i = 0;
        while(i &lt; len) {
            p = p-&gt;next;
            ++i;
        }
        ListNode* q = head;
        while(p-&gt;next) {
            p = p-&gt;next;
            q = q-&gt;next;
        }
        p-&gt;next = head;
        head = q-&gt;next;
        q-&gt;next = NULL;
        return head;
    }
};