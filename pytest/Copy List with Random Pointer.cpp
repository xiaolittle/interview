/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL) {
            return NULL;
        }
        RandomListNode *p = head;
        while(p) {
            RandomListNode *cur = new RandomListNode(p-&gt;label);
            cur-&gt;next = p-&gt;next;
            p-&gt;next = cur;
            p = cur-&gt;next;
        }
        
        p = head;
        while(p) {
            RandomListNode *cur = p-&gt;next;
            if(p-&gt;random) {
                cur-&gt;random = p-&gt;random-&gt;next;
            }
            p = cur-&gt;next;
        }
        
        p = head;
        RandomListNode *newhead = head-&gt;next;
        while(p) {
            RandomListNode *cur = p-&gt;next;
            p-&gt;next = cur-&gt;next;
            if(p-&gt;next) {
                cur-&gt;next = p-&gt;next-&gt;next;
            }
            p = p-&gt;next;
        }
        return newhead;
    }
};