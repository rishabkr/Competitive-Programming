class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    
    bool is_valid(int i,int j,vector<vector<char>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        return (i >=0 and i<m and j>=0 and j<n and grid[i][j]!='0');
    }
    int ans;
    void dfs(int i,int j,vector<vector<char>>&grid)
    { 
        if(is_valid(i,j,grid))
        {
            if(grid[i][j]=='1')
            {
                grid[i][j]='0';
            }          
            for(int k=0;k<4;k++)
            {
                int next_i=i+dx[k];
                int next_j=j+dy[k];
                
                dfs(next_i,next_j,grid);        
            }
            
        }
       
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {   
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};