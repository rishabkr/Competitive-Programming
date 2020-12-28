class Solution {
public:
    
    void dfs(vector<vector<char>>&board,int i,int j)
    {
        if(i>=0 and i<board.size() and j>=0 and j<board[0].size() and board[i][j]=='O')
        {
            board[i][j]='M';
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r<=2)
            return;
        int c=board[0].size();
        if(c<=2)
            return;
        
        //first check and mark all the boundary O s
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O' and (i==0 or i==r-1 or j==0 or j==c-1))
                {
                    dfs(board,i,j);
                }
            }
        }
        
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                {
                board[i][j]='X';
                }
                else if(board[i][j]=='M')
                {
                board[i][j]='O';
                }
                
            }
        }

        

    }
};