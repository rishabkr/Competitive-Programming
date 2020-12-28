class Solution {
public:

    vector<vector<bool>>visited;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    
    
    void valid_dfs(int x, int y,vector<vector<int>>&heights,int mid)
    {
        if(!visited[x][y])
        {
            visited[x][y]=1;
            
            int m=heights.size();
            int n=heights[0].size();

            for(int k=0;k<4;k++)
            {
                int next_x=x+dx[k];
                int next_y=y+dy[k];
                
                if(next_x < 0 or next_y<0 or next_x >=m  or next_y >= n)
                {
                    continue;
                }
                
                    if(abs(heights[next_x][next_y] - heights[x][y]) <= mid)
                        valid_dfs(next_x,next_y,heights,mid);
                
            }
        }
        
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left=0;
        int right=1e9+1;
        
        int m=heights.size();
        int n=heights[0].size();
        
        
        
        while(left <  right)
        {
            int mid=(left + right)/2;
            visited.assign(m,vector<bool>(n,0));        
            
            valid_dfs(0,0,heights,mid);
            if(visited[m-1][n-1]==1)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }

        }
        
        return left;
    }
};