/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Myclass {
	bool operator() (ListNode* a, ListNode* b) const {return a->val > b->val;}
} mycompare;
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = lists.size();
		ListNode* head = NULL;
		ListNode* cur = NULL;
		if(len <= 0) {
			return head;
		}
		vector<ListNode *> listcur;
		for(int i = 0; i < len; ++i) {
			if(lists[i] != NULL) {
				listcur.push_back(lists[i]);
			}
		}

		make_heap(listcur.begin(), listcur.end(), mycompare);
		while(listcur.size() > 0) {
			if(listcur.front() != NULL) {
				if(head == NULL) {
					head = listcur.front();
					cur = head;
				} else {
					cur->next = listcur.front();
					cur = cur->next;
				}
				ListNode* tmp = listcur.front()->next;
				pop_heap(listcur.begin(), listcur.end(), mycompare);
				listcur.pop_back();
				if(tmp != NULL) {
					listcur.push_back(tmp);
					push_heap(listcur.begin(), listcur.end(), mycompare);
				}
			}
		}
		return head;
    }
};