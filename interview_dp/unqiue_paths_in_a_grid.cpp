int Solution::uniquePaths(int m, int n) {
    
    int dp[m][n];
    
    for(int i=0; i < m ; i++)
    {
        for(int j=0;j < n; j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=1;
                continue;
            }
            else
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}


    vector<vector<int>>dp;

    int count(int i,int j,int m,int n)
    {
        if(i==m-1 and j==n-1)
        {
            return 1;
        }
        if(i>=m or j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        return dp[i][j]=count(i+1,j,m,n)+count(i,j+1,m,n);
    }

int Solution::uniquePaths(int m, int n) {
              dp.clear();

       dp.resize(m,vector<int>(n,-1));
       return int(count(0,0,m,n));
       
}


class Solution {
public:
        
    int uniquePaths(int m, int n) {
        // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
            long long ans = 1;
            for (int i = n; i < (m + n - 1); i++) {
                ans *= i;
                ans /= (i - n + 1);
            }
            return (int)ans;
    }
};
