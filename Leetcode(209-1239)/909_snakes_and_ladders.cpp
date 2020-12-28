class Solution {
public:
    
    int get_square_index(int square,int board_size)
    {
     int quotient=(square-1)/board_size;
     int row_number=board_size-1-quotient;
    int remainder=(square-1)%board_size;
        int column;
        if(board_size%2 != row_number%2)
        {
            column=remainder;
        }
        else
        {
            column=board_size-1-remainder;
        }
    return row_number*board_size+column;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        if(!board.size())
        {
            return -1;
        }
        int n=board.size();
        unordered_map<int,int>distance;
        distance[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int square=q.front();
            q.pop();
            if(square==n*n)
                return distance[square];
            
            for(int next_square=square+1;next_square<=min(square+6,n*n);next_square++)
            {
                int row_col=get_square_index(next_square,n);
                int row=row_col/n;
                int col=row_col%n;
                int curr_square;
                if(board[row][col]==-1)
                {
                    curr_square=next_square;
                }
                else
                {
                    curr_square=board[row][col];
                }
                
                if(distance.find(curr_square)==distance.end())
                {
                    distance[curr_square]=distance[square]+1;
                    q.push(curr_square);
                }
                
            }
            
        }
        return -1;
    }
};