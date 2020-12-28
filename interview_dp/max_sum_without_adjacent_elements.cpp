int Solution::adjacent(vector<vector<int> > &arr) {
    
    //init inclusion...exlucsion of first ele is already 0;
    int n=arr[0].size();
    vector<vector<int>>dp(2,vector<int>(n+1,0));
    dp[0][1]=max(arr[0][0],arr[1][0]);

    for(int i=2;i<=n;i++)
    {
        dp[0][i]=dp[1][i-1]+  max(arr[0][i-1],arr[1][i-1]); //include current element
        dp[1][i]=max(dp[0][i-1],dp[1][i-1]); //exlcude current element
    }
    return max(dp[0][n],dp[1][n]);
}