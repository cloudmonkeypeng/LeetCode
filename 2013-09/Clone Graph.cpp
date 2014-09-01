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
    UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node) {
        
        if(node == nullptr) return nullptr;
        // key is original node,value is copied node unordered_map<const UndirectedGraphNode *,
        
        
        unordered_map<const UndirectedGraphNode *,UndirectedGraphNode *> copied;
        
        clone(node, copied);
        
        return copied[node];
    }

 private:

 	 static UndirectedGraphNode* (ccloneonst UndirectedGraphNode *node,
                                      unordered_map<const UndirectedGraphNode *,UndirectedGraphNode *> &copied) {
        // a copy already exists
        if (copied.find(node) != copied.end()) return copied[node];
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        
        copied[node] = new_node;
        
//        for (auto nbr : node->neighbors)
//            new_node->neighbors.push_back(clone(nbr, copied));
        
        for(int i=0;i<node->neighbors.size();i++)
            new_node->neighbors.push_back(clone(node->neighbors[i], copied));
        
        return new_node;
    }
};