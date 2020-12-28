#define mod 1000000007
void dfs(vector<vector<int>>&adj,int current,int parent,long long &ans,long long sum,vector<int>&weights)
{
    int x=weights[current-1];
    for(auto neighbour : adj[current])
    {
        if(neighbour != parent)
        {
            dfs(adj,neighbour,current,ans,sum,weights);
            x+=weights[neighbour-1];
        }
    }
    weights[current-1]=x;
    if(current==1)
    {
        return;
    }
    ans=max(ans,(x*(sum-x))%mod)%mod;
}

int Solution::deleteEdge(vector<int> &weights, vector<vector<int> > &edges) {
    
    int n=weights.size();
    
    vector<vector<int>>adj(n+1);
    
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    long long sum=0;
    for(int x : weights)
    {
        sum+=x;
    }
    
    long long ans=0;
    dfs(adj,1,0,ans,sum,weights);
    return ans;
}
