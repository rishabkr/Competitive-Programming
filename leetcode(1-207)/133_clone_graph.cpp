/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


Node* clone_node(Node* node,unordered_map<int,Node*>&visited)
{
    
    Node* new_node_clone=new Node(node->val);
    
    visited[node->val]=new_node_clone;
    
    for(Node* neighbor : node->neighbors)
    {
        
        auto it = visited.find(neighbor->val);
        
        if(it==visited.end())
        {
            Node* clone_neighbor=clone_node(neighbor,visited);
            
            new_node_clone->neighbors.push_back(clone_neighbor);          
        }
        else
        {
            new_node_clone->neighbors.push_back(it->second);    
        }
    }
    return new_node_clone;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
    
        if(!node)
        {
            return NULL;
        }
        
     unordered_map<int,Node*>visited;        
    return clone_node(node,visited);
    }
};