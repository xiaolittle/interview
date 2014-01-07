/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode* > hash;
 //       unordered_set<UndirectedGraphNode*> visit;
        queue<UndirectedGraphNode*> q;
        if(node == NULL) {
            return NULL;
        }
        q.push(node);
 //       visit.insert(node);
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        hash[node] = root;
        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            int n = cur->neighbors.size();
            for(int i = 0; i < n; ++i) {
                UndirectedGraphNode* curnode = cur->neighbors[i];
                if(hash.count(curnode) == 0) {
                    UndirectedGraphNode *newnode = new UndirectedGraphNode(curnode->label);
                    hash[cur]->neighbors.push_back(newnode);
                    hash[curnode] = newnode;
                    q.push(curnode);
                } else {
                    hash[cur]->neighbors.push_back(hash[curnode]);
                }
 //               if(visit.count(curnode) == 0) {
 //                   q.push(curnode);
 //               } // visit的方法是不行的，因为 0,1,2互联的时候，2已经进入queue了，但是还没有visit，会被反复放入q
            }
 //           visit.insert(cur);
        }
        return root;
    }
};
