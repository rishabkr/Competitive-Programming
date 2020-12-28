class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>visited;
    vector<int>label;
    vector<int>low;
    
    vector<vector<int>>res;
    int curr_depth=0;
    
    void dfs(vector<vector<int>>&adj,int node,int parent)
    {
        visited[node]=true;
        label[node]=curr_depth;
        low[node]=curr_depth;
        curr_depth+=1;
        
        for(auto neighbor : adj[node])
        {
            if(neighbor == parent)
                continue;
            
            if(!visited[neighbor])
            {
                dfs(adj,neighbor,node);
                
                low[node]=min(low[node],low[neighbor]);
                
                if(label[node] < low[neighbor])
                {
                    res.push_back({node,neighbor});
                }
            }
            else //if visited
            {
                low[node]=min(low[node],low[neighbor]);
            }
        }
    }
        
        
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        adj.resize(n);
        visited.assign(n,false);
        label.assign(n,-1);
        low.assign(n,-1);
        curr_depth=0;
        
        for(auto connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        dfs(adj,0,-1);
        
        return res;
    }
};