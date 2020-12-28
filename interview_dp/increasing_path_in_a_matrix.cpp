int Solution::solve(vector<vector<int> > &arr) {
  int m=arr.size();
        int n=arr[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        dp[0][0]=1;
        for(int i=1;i<n;i++)
        {
            if(arr[0][i] > arr[0][i-1])
            {
                dp[0][i]=dp[0][i-1]+1;
            }
            else
            {
                break;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            if(arr[i][0] > arr[i-1][0])
            {
                dp[i][0]=dp[i-1][0]+1;
            }
            else
            {
                break;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(  arr[i][j] > arr[i-1][j] and dp[i-1][j]!=0)
                {
                    dp[i][j]=dp[i-1][j]+1;
                }
                
                if(  arr[i][j] > arr[i][j-1]  and dp[i][j-1]!=0)
                {
                    dp[i][j]=dp[i][j-1]+1;
                }

            }
        }
        return dp[m-1][n-1]!=0?dp[m-1][n-1]:-1;
    
    
}
