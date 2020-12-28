int Solution::solve(vector<int> &prices, int k) {
    
    if(k==0 or prices.size()<2)
    {
        return 0;
    }
    if(k > prices.size())
    {
        k=prices.size()/2;
    }
    
    vector<vector<int>>dp(k+1,vector<int>(prices.size(),0));
    
    int max_prof=0;
    int minp=prices[0];
    
    for(int i=1;i<prices.size();i++)
    {
        minp=min(minp,prices[i]);
        max_prof=max(max_prof,prices[i]-minp);
        dp[1][i]=max_prof;
    }
    
    for(int i=2;i<=k;i++)
    {
        int b2=INT_MAX;
        int p2=0;
        for(int j=0;j<prices.size();j++)
        {
            b2=min(b2,prices[j]-dp[i-1][j]);
            p2=max(p2,prices[j]-b2);
            dp[i][j]=p2;
        }
    }
    
    int ans=0;
    for(int i=0;i<prices.size();i++)
    {
        ans=max(ans,dp[k][i]);
    }
    return ans;
}
