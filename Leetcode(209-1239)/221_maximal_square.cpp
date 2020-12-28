class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m=matrix.size();
        int n=m>0?matrix[0].size():0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        int max_square_size=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    cout<<max_square_size<<" ";
                    max_square_size=max(max_square_size,dp[i][j]);
                }
            }
        }
        
        return max_square_size*max_square_size;
    }
};