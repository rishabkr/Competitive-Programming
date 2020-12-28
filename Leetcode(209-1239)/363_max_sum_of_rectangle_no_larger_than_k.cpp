class Solution {
public:
    
    int dp[2000][2000];
    
    void init(int m,int n)
    {
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=0;
        }
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        init(m+1,n+1);
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        int res=INT_MIN;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int x=1;x<=i;x++)
                {
                    for(int y=1;y<=j;y++)
                    {
                        int sum=INT_MIN;
                        
                        sum=dp[i][j] - dp[x-1][j] - dp[i][y-1] + dp[x-1][y-1];
                        if(sum <= k)
                        {
                            res=max(res,sum);
                        }
                    }
                }
            }
        }
        return res;
    }
};