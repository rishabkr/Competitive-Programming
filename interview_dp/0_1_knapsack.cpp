int Solution::solve(vector<int> &val, vector<int> &wt, int max_wt) {
    
    vector<vector<int>>dp(val.size()+1,vector<int>(max_wt+1,0));
    
    for(int i=1;i<=val.size();i++)
    {
        for(int j=1;j<=max_wt;j++)
        {
            
            if(wt[i-1] <= j)
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    
    return dp[val.size()][max_wt];
}
