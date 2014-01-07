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
        if (node == NULL) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> node_hash;
        queue<UndirectedGraphNode *> q;
        
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        q.push(node);
        node_hash[node] = root;
        
        while (!q.empty()) {
            UndirectedGraphNode *cur_node = q.front();
            q.pop();
            UndirectedGraphNode *cur_node2 = node_hash[cur_node];
            for (int i = 0; i < cur_node->neighbors.size(); ++i) {
                UndirectedGraphNode *neighbor = cur_node->neighbors[i];
                if (node_hash.count(neighbor)) {
                    cur_node2->neighbors.push_back(node_hash[neighbor]);
                } else {
                    UndirectedGraphNode *neighbor2 = new UndirectedGraphNode(neighbor->label);
                    cur_node2->neighbors.push_back(neighbor2);
                    node_hash[neighbor] = neighbor2;
                    q.push(neighbor);
                }
            }
        }
        return root;
    }
};
