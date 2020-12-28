int Solution::solve(vector<int> &arr) {
    
    int sum=0;
    for(int num : arr)
    {
        sum+=num;
    }

    int half_sum=sum/2;
    int n=arr.size();
    
    bool dp[n+1][half_sum+1];
    
     
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    dp[0][0]=1;
    
    
    for(int i=0;i<=half_sum;i++)
    {
        dp[0][i]=0;
    }

   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=half_sum;j++)
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
    
    for(int i=half_sum;i>=0;i--)
    {
        if(dp[n][i] == true)
        {
            return sum-(i*2);
        }
    }
    return 0;
}
