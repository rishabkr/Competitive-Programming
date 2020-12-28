int Solution::solve(vector<vector<int> > &arr, int k) {
    
    int rows=arr.size();
    int cols=arr[0].size();
    
    vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
    
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            dp[i][j]=arr[i-1][j-1]+ dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    int max_sum=INT_MIN;
    
    for(int i=1;i<=rows;i++)
    {
        for(int j=1;j<=cols;j++)
        {
            int current_sum=INT_MIN;
            if(i - k >=0 and j-k >=0)
            {
                current_sum = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
                max_sum=max(current_sum,max_sum);
            }
        }
    }
    return max_sum;
}
