class Solution {
public:
    //unordered_map<string,int>mp;
    vector<vector<vector<int>>>dp;
    bool is_safe(vector<vector<int>>&grid,int c1,int c2)
    {
        int n=grid[0].size();
        return c1>=0 and c2>=0 and c1<n and c2<n;
    }
    
    int solve(vector<vector<int>>&grid,int row_num,int c1,int c2)
    {
        
        if(row_num==grid.size())
        {
            return 0;
        }
        
        if(!is_safe(grid,c1,c2))
        {
            return INT_MIN;
        }
        
        //string key="";
        //key+=to_string(row_num)+" "+to_string(c1)+" "+to_string(c2);
        // if(mp.count(key)>0)
        // {
        //     return mp[key];
        // }
        if(dp[row_num][c1][c2]!=-1)
        {
            return dp[row_num][c1][c2];
        }
        
        int ans=INT_MIN;
        int current=0;
        if(c1!=c2)
        {
            current=current+grid[row_num][c1]+grid[row_num][c2];
        }
        else
        {
            current+=grid[row_num][c1];
        }
        int temp=INT_MIN;
        ans=max({current+solve(grid,row_num+1,c1-1,c2-1),
                  current+solve(grid,row_num+1,c1-1,c2),
                  current+solve(grid,row_num+1,c1-1,c2+1),
                  current+solve(grid,row_num+1,c1,c2-1),
                  current+solve(grid,row_num+1,c1,c2),
                  current+solve(grid,row_num+1,c1,c2+1),
                  current+solve(grid,row_num+1,c1+1,c2-1),
                  current+solve(grid,row_num+1,c1+1,c2),
                  current+solve(grid,row_num+1,c1+1,c2+1),
                });
        return dp[row_num][c1][c2]=ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        dp.assign(72,vector<vector<int>>(72,vector<int>(72,-1)));
        return max(0,solve(grid,0,0,grid[0].size()-1));
        
    }
};