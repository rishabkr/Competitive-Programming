class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        
        dp[0][0]=grid[0][0];
        
        for(int i=1;i<grid.size();i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        
        for(int i=1;i<grid[0].size();i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        cout<<"here\n";
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
            
    }
};