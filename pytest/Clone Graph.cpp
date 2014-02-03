/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector&lt;UndirectedGraphNode *&gt; neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map&lt;UndirectedGraphNode*, UndirectedGraphNode* &gt; hash;
 //       unordered_set&lt;UndirectedGraphNode*&gt; visit;
        queue&lt;UndirectedGraphNode*&gt; q;
        if(node == NULL) {
            return NULL;
        }
        q.push(node);
 //       visit.insert(node);
        UndirectedGraphNode *root = new UndirectedGraphNode(node-&gt;label);
        hash[node] = root;
        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            int n = cur-&gt;neighbors.size();
            for(int i = 0; i &lt; n; ++i) {
                UndirectedGraphNode* curnode = cur-&gt;neighbors[i];
                if(hash.count(curnode) == 0) {
                    UndirectedGraphNode *newnode = new UndirectedGraphNode(curnode-&gt;label);
                    hash[cur]-&gt;neighbors.push_back(newnode);
                    hash[curnode] = newnode;
                    q.push(curnode);
                } else {
                    hash[cur]-&gt;neighbors.push_back(hash[curnode]);
                }
 //               if(visit.count(curnode) == 0) {
 //                   q.push(curnode);
 //               }
            }
 //           visit.insert(cur);
        }
        return root;
    }
};