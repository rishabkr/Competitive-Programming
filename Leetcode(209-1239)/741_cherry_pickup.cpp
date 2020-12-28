class Solution {
public:
    vector<vector<vector<int>>>dp;

    
    bool is_not_safe(int r1,int c1,int r2,int c2,vector<vector<int>>&grid)
    {
        int n=grid.size();
        return (r1 >= n or r2 >= n or c1>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1);
    }
    
    int solve(int r1,int c1,int c2,int size,vector<vector<int>>&grid)
    {
        int r2=r1+c1-c2;
        
        if(is_not_safe(r1,c1,r2,c2,grid))
        {
            return INT_MIN;
        }
        
        if(r1==size-1 and c1==size-1)
        {
            return grid[r1][c1];
        }
        
        
        if(dp[r1][c1][c2]!=INT_MIN)
        {
            return dp[r1][c1][c2];
        }

        int ans=grid[r1][c1];
        if(c1!=c2)
        {
            ans+=grid[r2][c2];
        }
        
        int temp=max({solve(r1,c1+1,c2+1,size,grid),//both right
                      solve(r1+1,c1,c2,size,grid),//person 1 down person 2 down
                      solve(r1,c1+1,c2,size,grid),//person 1 right person 2 down
                      solve(r1+1,c1,c2+1,size,grid)//person 1 down person 2 right 
                    });
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
       
        dp.assign(n,vector<vector<int>>(n,vector<int>(n,INT_MIN))); //or int dp[n][n][n];
        
        return max(0,solve(0,0,0,n,grid));
    }
};