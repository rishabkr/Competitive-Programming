int Solution::solve(vector<int> &arr, int sum) {

    vector<vector<bool>>dp(arr.size()+1,vector<bool>(sum+1,0));
    sort(arr.begin(),arr.end());
    for(int j=0;j<=sum;j++)
    {
        dp[0][j]=0;
    }
    for(int i=0;i<=arr.size();i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=arr.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            
            if(arr[i-1] <= j)
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[arr.size()][sum];
}
