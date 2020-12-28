
typedef pair<int,int>pi;

vector <int> dijkstra(vector<vector<int>> grid, int src, int n)
{
    // Your code here
    
    vector<int>distance(n+1,INT_MAX);
    vector<bool>visited(n+1,0);
    
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    
    pq.push({0,src});
    distance[src]=0;
    
    while(!pq.empty())
    {
        auto current=pq.top();
        pq.pop();
        
        int current_node=current.second;
        
        if(visited[current_node])
        {
            continue;
        }
        visited[current_node]=true;
        
        for(int i=0;i<n;i++)
        {
            if(grid[current_node][i] != 0)
            {
                int next_node=i;
                int dist=grid[current_node][next_node];
                
                if(distance[next_node] >  distance[current_node] + dist )
                {
                    distance[next_node]=distance[current_node]+grid[current_node][next_node];
                    pq.push({distance[next_node],next_node});
                }
                
            }
        }
    }
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        res.push_back(distance[i]);
    }
    return res;
}