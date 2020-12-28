
void dfs(int row,int col,int previous,vector<vector<int>>&matrix,vector<vector<int>>&reachable)
{
    if(row < 0 or col <0 or row >= matrix.size() or col >= matrix[0].size())
    {
        return;
    }
    if(reachable[row][col]==1)
    {
        return;//alreay visited
    }
    if(matrix[row][col] < previous)
    {
        return;
    }
    
    reachable[row][col]=1;
    
    dfs(row+1,col,matrix[row][col],matrix,reachable);
    dfs(row,col+1,matrix[row][col],matrix,reachable);
    dfs(row-1,col,matrix[row][col],matrix,reachable);
    dfs(row,col-1,matrix[row][col],matrix,reachable);

}

int Solution::solve(vector<vector<int> > &matrix) {
    
        if(!matrix.size())
        {
            return 0;
        }
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>red;
        vector<vector<int>>blue;
        
        red.assign(rows,vector<int>(cols,0));
        blue.assign(rows,vector<int>(cols,0));
        
        for(int i=0;i<cols;i++)
        {
            dfs(0,i,INT_MIN,matrix,blue);
        }
        
        for(int i=0;i<rows;i++)
        {
            dfs(i,0,INT_MIN,matrix,blue);
        }
        
        for(int i=0;i<cols;i++)
        {
            dfs(rows-1,i,INT_MIN,matrix,red);
        }
        
        for(int i=0;i<rows;i++)
        {
            dfs(i,cols-1,INT_MIN,matrix,red);
        }
        int count=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(blue[i][j]==1 and red[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
}
