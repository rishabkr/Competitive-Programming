class Solution {
public:
    
    void find_meeting_points(vector<vector<int>>&pacific,vector<vector<int>>&atlantic,vector<vector<int>>&res)
    {
        for(int i=0;i<pacific.size();i++)
        {
            for(int j=0;j<pacific[0].size();j++)
            {
                if(pacific[i][j]== 1 and atlantic[i][j]==1)
                {
                    res.push_back({i,j});
                }
            }
        }
    }
    
    void dfs(int row,int col,int previous,vector<vector<int>>&matrix,vector<vector<int>>&temp)
    {
        if(row <0 or row>=matrix.size() or col<0 or col>=matrix[0].size())
        {
            return;
        }
        if(temp[row][col]==1)//if already visited
        {
            return;
        }
        if(matrix[row][col] < previous) // if curretn value is less than previous seen
        {
            return;
        }
        temp[row][col]=1;
        
        dfs(row+1,col,matrix[row][col],matrix,temp);
        dfs(row-1,col,matrix[row][col],matrix,temp);
        dfs(row,col+1,matrix[row][col],matrix,temp);
        dfs(row,col-1,matrix[row][col],matrix,temp);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>>res;        
        
        if(!matrix.size())
        {
            return res;
        }
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        vector<vector<int>>pacific(rows,vector<int>(cols,0));
        vector<vector<int>>atlantic(rows,vector<int>(cols,0));
        
        //for pacific first row
        for(int i=0;i<cols;i++)
        {
            dfs(0,i,INT_MIN,matrix,pacific);
        }
        
        // for pacific first col
        for(int i=0;i<rows;i++)
        {
            dfs(i,0,INT_MIN,matrix,pacific);
        }

        
        //for atlantic last row
        for(int i=0;i<cols;i++)
        {
            dfs(rows-1,i,INT_MIN,matrix,atlantic);
        }

        //for atlantic last col
        for(int i=0;i<rows;i++)
        {
            dfs(i,cols-1,INT_MIN,matrix,atlantic);
        }

        find_meeting_points(pacific,atlantic,res);
        
        return res;
    }
};