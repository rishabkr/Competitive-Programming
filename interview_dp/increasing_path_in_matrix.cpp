bool isSafe(int i,int j,vector<vector<int> > &A)
{
    return (i>=0)&&(i<A.size())&&(j>=0)&&(j<A[0].size());
}
int dfs(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &A,bool &visited)
{
    if(i==A.size()-1&&j==A[0].size()-1)
    {
        visited=true;
        return 1;
    }
    
    if(dp[i][j]!=-1)
    {
    	return dp[i][j];
    }

    if(isSafe(i+1,j,A)&&A[i+1][j]>A[i][j]) 
    {
    	dp[i][j]=max(dp[i][j],1+dfs(i+1,j,dp,A,visited));
    }
    
    if(isSafe(i,j+1,A)&&A[i][j+1]>A[i][j])
    {
    	dp[i][j]=max(dp[i][j],1+dfs(i,j+1,dp,A,visited));
    }
    return dp[i][j];
}
int Solution::solve(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int> (A[0].size(),-1));
    bool visited =false;
    int v=dfs(0,0,dp,A,visited);
    return visited?v:-1;
}