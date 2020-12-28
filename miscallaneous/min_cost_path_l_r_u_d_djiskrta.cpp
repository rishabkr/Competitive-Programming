//https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1#

typedef pair<long long int,pair<int, int>> ppi; 

bool is_safe(int i,int j, int n)
{
    return i>=0 and i<n and j>=0 and j<n;
}

int shortest(vector<vector<int> > &grid, int n) {
    vector<vector<long long int>>distance(n,vector<long long int>(n,INT_MAX));
    distance[0][0]=grid[0][0];
    
    set<ppi>st;
    
    st.insert({distance[0][0],{0,0}});
    
    int dx[4]={0,-1,1,0};
    int dy[4]={-1,0,0,1};
    
    while(!st.empty())
    {
        ppi node=*st.begin();
        st.erase(st.begin());
        
        long long int curr_dist=node.first;
        int curr_x=node.second.first;
        int curr_y=node.second.second;
        
        if(curr_x==n-1 and curr_y==n-1)
        {
            return distance[n-1][n-1];
        }
        
        
        for(int i=0;i<4;i++)
        {
            int next_x=curr_x+dx[i];
            int next_y=curr_y+dy[i];
            
            
            if(is_safe(next_x,next_y,n) and distance[next_x][next_y] > curr_dist + grid[next_x][next_y])
            {
                
                if(distance[next_x][next_y]!=INT_MAX)
                {
                    st.erase({distance[next_x][next_y],{next_x,next_y}});
                }
                
                distance[next_x][next_y]=curr_dist+grid[next_x][next_y];
                st.insert({distance[next_x][next_y],{next_x,next_y}});
            }
        }
        
    }
    return distance[n-1][n-1];
    
}