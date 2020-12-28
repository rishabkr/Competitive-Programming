
void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj)
{
    visited[node]=true;
    
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour,visited,adj);
        }
    }
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
    }
    
    vector<bool>visited(n+10,0);
    dfs(0,visited,adj);
 return visited[n-1];   
}
