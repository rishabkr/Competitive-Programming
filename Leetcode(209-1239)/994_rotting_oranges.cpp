class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int res=-1;
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,-1,0,1};
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(!grid.size())
        {
            return 0;
        }
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    fresh+=1;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
        int size=q.size();
        while(size--)
        {
            auto front=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=front.first+dirx[i];
                int y=front.second+diry[i];
                if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y]==1)
                {
                    grid[x][y]=2;
                    q.push({x,y});
                    fresh-=1;
                }
            }
            
        }
        res+=1;            
        }
        if(fresh>0)//if fresh>0 that means there are fresh oranges left
        {
            return -1;
        }
        if(res==-1)//we initialised with -1, so if there were no oranges it'd take 0 mins.
        {
            return 0;
        }
        return res;        
    }
};