class Solution {
public:
    
    int ans;
    
    
    int is_safe(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        return (i>=0 and j>=0 and i<m and j<n and !visited[i][j] and grid[i][j]);
    }
    
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    
    void solve(int i,int j,int res,int &ans,vector<vector<int>>&grid,vector<vector<bool>>&visited)
    {
        if(!is_safe(i,j,grid,visited))
        {
            return;
        }
        
        visited[i][j]=1;
        
        res+=grid[i][j];
        ans=max(ans,res);
        
        for(int k=0; k < 4; k++)
        {
            int next_i= i+dx[k];
            int next_j= j+dy[k];
   
            solve(next_i,next_j,res,ans,grid,visited);
        }
        
        
        visited[i][j]=0;
        res-=grid[i][j];
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>visited;

        visited.assign(m,vector<bool>(n,false));
        
      
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    continue;
                }
                solve(i,j,0,ans,grid,visited);
            }
        }
        return ans;
    }
};