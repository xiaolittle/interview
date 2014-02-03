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
    struct Compare {
        typedef ListNode* ListNodePtr;
        bool operator() (const ListNodePtr a, const ListNodePtr b) {return a-&gt;val &gt; b-&gt;val;}
    };
    
    ListNode *mergeKLists(vector&lt;ListNode *&gt; &amp;lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = lists.size();
        ListNode* head = NULL;
        if(n == 0) {
            return head;
        } else if(n == 1) {
            return lists[0];
        }
        vector&lt;ListNode *&gt; v;
        for(int i = 0; i &lt; n; ++i) {
            if(lists[i]) {
                v.push_back(lists[i]);
            }
        }
        make_heap(v.begin(), v.end(), Compare());
        ListNode* last = NULL;
        while(v.size() &gt; 0) {
            ListNode* cur = v.front();
            if(head == NULL) {
                head = cur;
                last = head;
            } else {
                last-&gt;next = cur;
                last = cur;
            }
            pop_heap(v.begin(), v.end(), Compare());
            v.pop_back();
            if(cur-&gt;next) {
                v.push_back(cur-&gt;next);
                push_heap(v.begin(), v.end(), Compare());
            }
        }
        return head;
    }
};