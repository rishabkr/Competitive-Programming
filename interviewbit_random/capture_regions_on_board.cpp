int row;
int col;

void dfs(vector<vector<char>>&A,int i,int j)
{
    if(i<0|i>=row||j<0||j>=col||A[i][j]!='O')
        return;
    
    //step2
    A[i][j] = '#';
    
    dfs(A,i-1,j);//up
    dfs(A,i+1,j);//down
    dfs(A,i,j-1);//left
    dfs(A,i,j+1);//right
}

void Solution::solve(vector<vector<char> > &A) 
{
    /*
    //Approach:
//1) Scan the borders of the matrix
//2) if any 'O' visit all the chaining 'O' and make them '#'
//3) make all other 'O' to 'X' and '#' to 'O'
    */
    row = A.size();
    if(row == 0)
        return;
    col = A[0].size();
    
    
    //step1.1
    //sweep first and last columns
    for(int i=0;i<row;i++)
    {
        if(A[i][0] == 'O')
            dfs(A,i,0);
        if(A[i][col-1] == 'O')
            dfs(A,i,col-1);
    }
    
    //step1.2
    //sweep first last rows
    for(int j=0;j<col;j++)
    {
        if(A[0][j] == 'O')
            dfs(A,0,j);
        
        if(A[row-1][j] == 'O')
            dfs(A,row-1,j);
    }
    
    //step3
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(A[i][j] == 'O')
                A[i][j] = 'X';
            else if(A[i][j] == '#')
                A[i][j] = 'O';
}