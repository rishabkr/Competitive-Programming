vector<bool>visited;
bool cycle=false;
vector<bool>on_stack;


void dfs(int node,vector<vector<int>>&adj)
{
    visited[node]=true;
    on_stack[node]=true;
    
    for(int neighbour : adj[node])
    {
     if(visited[neighbour] and on_stack[neighbour])
         {
            cycle=true;
            return;
         }
         dfs(neighbour,adj);
    }
    
    on_stack[node]=false;
}

int Solution::solve(int n, vector<vector<int> > &edges) {
    visited.clear();
    on_stack.clear();
    
    visited.resize(n+10,0);
    on_stack.resize(n+10,0);
    vector<vector<int>>adj(n+1);
    
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    cycle=false;
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj);
            if(cycle==true)
            {
                break;
            }
        }
    }
    return cycle;
}
