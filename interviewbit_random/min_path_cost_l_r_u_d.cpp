#define pii pair<int,pair<int,int>>
char dir[4]={'L','R','U','D'};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool is_safe(int i,int j,int m,int n)
{
    return i>=0 and i<m and j>=0 and j<n;
}

int Solution::solve(int m, int n, vector<string> &mat) {
    
    vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
    distance[0][0]=0;
    
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    
    pq.push({distance[0][0],{0,0}});
    
    while(!pq.empty())
    {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        
        pq.pop();
        
        for(int k=0;k<4;k++)
        {
            int next_x=x+dx[k];
            int next_y=y+dy[k];
            int next_cost=0;
            if(mat[x][y] == dir[k])
            {
                next_cost=0;    
            }
            else
            {
                next_cost=1;
            }
            
            if(is_safe(next_x,next_y,m,n))
            {
                if(distance[x][y] + next_cost < distance[next_x][next_y])
                {
                    distance[next_x][next_y]=distance[x][y]+next_cost;
                    pq.push({distance[next_x][next_y],{next_x,next_y}});
                }
            }
        }
        
    }
    
    return distance[m-1][n-1];
}
