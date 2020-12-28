class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int dfs(int i,int j,int previous_value,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        if(i>=mat.size() or j>= mat[0].size() or i<0 or j < 0)
        {
            return 0;
        }
        else if(previous_value>= mat[i][j])
        {
            return 0;
        }
        else if(dp[i][j]!=0)
        {
            return dp[i][j];
        }
        
        int len1=dfs(i+1,j,mat[i][j],mat,dp);
        int len2=dfs(i-1,j,mat[i][j],mat,dp);
        int len3=dfs(i,j+1,mat[i][j],mat,dp);
        int len4=dfs(i,j-1,mat[i][j],mat,dp);
        
        int max1=max(len1,len2);
        int max2=max(len3,len4);
        
        dp[i][j]=1+max(max1,max2);
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size())
        {
            return 0;
        }
        int max_len=0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(!dp[i][j])
                {
                    dfs(i,j,INT_MIN,matrix,dp);
                    max_len=max(max_len,dp[i][j]);
                }
            }
        }
    
        return max_len;
    }
};