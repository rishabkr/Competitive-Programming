int Solution::solve(vector<vector<int> > &A) {
    if(!A.size())
    {
        return 0;
    }
    
    int dp[A.size()][A[0].size()]={0};
    dp[0][0]=1;
    for(int i=1;i<A[0].size();i++)
    {
        if(A[0][i] > A[0][i-1])
        {
            dp[0][i]=1+dp[0][i-1];
        }
        else
        {
            break;
        }
    }
    
        for(int i=1;i<A.size();i++)
    {
        if(A[i][0] > A[i-1][0])
        {
            dp[i][0]=1+dp[i-1][0];
        }
        else
        {
            break;
        }
    }


    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<A[i].size();j++)
        {   //up increasing and reachable
            if(A[i][j] > A[i-1][j] and dp[i-1][j] !=0)
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            //left incresing and reachable
            if(A[i][j] > A[i][j-1] and dp[i][j-1]!=0)
            {
                dp[i][j]=max(dp[i][j-1]+1,dp[i][j]);
            }
        }
    }
    
     
       int n = A.size()-1;
       int m = A[0].size()-1;
       
       if(dp[n][m]==0)return -1;
       else return dp[n][m];
}
//below is dfs version.cool

/*bool isSafe(int i,int j,vector<vector<int> > &A)
{
    return (i>=0)&&(i<A.size())&&(j>=0)&&(j<A[0].size());
}
int dfs(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &A,bool &visited)
{
    if(i==A.size()-1&&j==A[0].size()-1){
        visited=true;
        return 1;}
    if(dp[i][j]!=-1) return dp[i][j];
    if(isSafe(i+1,j,A)&&A[i+1][j]>A[i][j]) dp[i][j]=max(dp[i][j],1+dfs(i+1,j,dp,A,visited));
    if(isSafe(i,j+1,A)&&A[i][j+1]>A[i][j]) dp[i][j]=max(dp[i][j],1+dfs(i,j+1,dp,A,visited));
    return dp[i][j];
}
int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int> (A[0].size(),-1));
    bool visited =false;
    int v=dfs(0,0,dp,A,visited);
    return visited?v:-1;
}*/