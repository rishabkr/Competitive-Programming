
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int dfs(int i,int j,vector<vector<int>>&mat)
{
    if(i<0 or j < 0 or i>=mat.size() or j>=mat[0].size() or mat[i][j]==0)
    {
        return 0;
    }
    int count=0;    
    if(mat[i][j]==1)
    {
        count=1;
        mat[i][j]=0;
    }

    for(int k=0;k<8;k++)
    {
        count+=dfs(i+dx[k],j+dy[k],mat);
    }
    return count;
}

int Solution::solve(vector<vector<int> > &mat) {
    
    int max_size=0;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            int count=0;
            if(mat[i][j]==1)
            {
                count=dfs( i, j,mat);
                max_size=max(count,max_size);
            }
        }
    }
    return max_size;
}
