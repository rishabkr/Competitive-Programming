vector<int>colour;
vector<int>visited;
 
bool dfs(int node,int col,vector<vector<int>>&adj)
{
    visited[node]=1;
    colour[node]=col;
    
    for(int neighbour :  adj[node])
    {
        if(!visited[neighbour])
        {
            if(dfs(neighbour,col^1,adj) == false)
            {
                return false;
            }
        }
        else if(colour[neighbour]==colour[node])
        {
            return false;
        }
    }
    return true;
}
 
int Solution::solve(int n, vector<vector<int> > &edges) {
        visited.assign(n+5,0);
        colour.assign(n+5,-1);
        vector<vector<int>>adj(n);
 
        for(auto edge : edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i] and dfs(i,0,adj)==false)
            {
                return false;
            }
        }
    return true;
}