class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     vector<vector<int>>mat(n,vector<int>(n));
    if(n==0)
    {
        return mat;
    }
    int c_count=1;
    vector<int> sqrs;
    for(int i=1;i<=n*n;i++)
    {
        sqrs.push_back(i);
    }
    int row_start=0;
    int row_end=n-1;
    int col_start=0;
    int col_end=n-1;
    while(row_start<=row_end && col_start<=col_end)
    {
        for(int i=col_start;i<=col_end;i++)
        {
            mat[row_start][i]=c_count++;
          
        }
        row_start++;
        for(int i=row_start;i<=row_end;i++)
        {
            mat[i][col_end]=c_count++;
        }
        col_end--;
        if(row_start<=row_end)
        {
            for(int i=col_end;i>=col_start;i--)
            {
                mat[row_end][i]=c_count++;
    
            }
        }
        row_end--;
        if(col_start<=col_end)
        {
            for(int i=row_end;i>=row_start;i--)
            {
                mat[i][col_start]=c_count++;
            }
        }
        col_start++;
    }
        
        
    return mat;
    }
};