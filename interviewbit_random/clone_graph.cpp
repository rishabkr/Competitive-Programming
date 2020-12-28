/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 UndirectedGraphNode* clone_node(UndirectedGraphNode* node,unordered_map<int,UndirectedGraphNode*>&visited)
{
    
    UndirectedGraphNode* new_node_clone=new UndirectedGraphNode(node->label);
    
    visited[node->label]=new_node_clone;
    
    for(UndirectedGraphNode* neighbor : node->neighbors)
    {
        
        auto it = visited.find(neighbor->label);
        
        if(it==visited.end())
        {
            UndirectedGraphNode* clone_neighbor=clone_node(neighbor,visited);
            
            new_node_clone->neighbors.push_back(clone_neighbor);          
        }
        else
        {
            new_node_clone->neighbors.push_back(it->second);    
        }
    }
    return new_node_clone;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {

        if(!node)
        {
            return NULL;
        }
        
     unordered_map<int,UndirectedGraphNode*>visited;        
    return clone_node(node,visited);
}
