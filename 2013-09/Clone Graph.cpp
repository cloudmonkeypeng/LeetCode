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



///广度优先遍历，一次通过

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if(node==NULL)
            return node;
        
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        
        UndirectedGraphNode *root =new UndirectedGraphNode(node->label);
        
        map[node] = root;
        
        queue<UndirectedGraphNode *> q;
        
        q.push(node);
        
        
        while(!q.empty()){
        
            UndirectedGraphNode *temp = q.front();
            
            q.pop();
            
            for(int i=0;i<temp->neighbors.size();i++){
            
                if(map.find(temp->neighbors[i])==map.end()){
                
                    UndirectedGraphNode *tempNewGraph =new UndirectedGraphNode(temp->neighbors[i]->label);
                    
                    map[temp->neighbors[i]] = tempNewGraph;
                    
                    q.push(temp->neighbors[i]);
                }
                
                
                map[temp]->neighbors.push_back(map[temp->neighbors[i]]);
            }
        
        
        }

        return root;
    }
};

