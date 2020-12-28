int Solution::numTrees(int n) {
    int dp[n+1]={0};
    
    dp[0]=1;//C0
    dp[1]=1;//C1
    //find Cn == 2nCn/N+1== eg. C3= C0.C2 + C1.C1 + C2C0
    
    for(int i=2;i<=n;i++)
    {
        int left=0;
        int right=i-1;
        
        while(left <= i-1)
        {
            dp[i]+=(dp[left] * dp[right]);
            left++;
            right--;
        }
    }
    return dp[n];
}
