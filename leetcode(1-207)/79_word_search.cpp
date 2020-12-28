
//O(1) space complexity
class Solution {
public:
    
    
    bool search(int i,int j,int index,string &word,vector<vector<char>>& board)
    {
      if(index==word.length()-1)
      {
          return true;
      }
      board[i][j]-=65; //visited[i][j]=true;
      
      if(i > 0 and  board[i-1][j]==word[index+1] and search(i-1,j,index+1,word,board))
      {
          return true;
      }
      
        if(j> 0 and  board[i][j-1]==word[index+1] and search(i,j-1,index+1,word,board))
      {
          return true;
      }
      
if(i < board.size()-1 and board[i+1][j]==word[index+1] and search(i+1,j,index+1,word,board))
      {
          return true;
      }
if(j< board[0].size()-1 and  board[i][j+1]==word[index+1] and                                                                                                                 search(i,j+1,index+1,word,board))
      
     {
          return true;
     }
        
        
         board[i][j]+=65; //visited[i][j]=false;
        return false;
    } 
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j] and search(i,j,0,word,board))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//O(MN) Space Complexity
/*class Solution {
public:
    
    
    bool search(int i,int j,int index,string &word,vector<vector<char>>& board,vector<vector<bool>>&visited)
    {
      if(index==word.length()-1)
      {
          return true;
      }
      visited[i][j]=true;
      
      if(i > 0 and !visited[i-1][j] and board[i-1][j]==word[index+1] and search(i-1,j,index+1,word,board,visited))
      {
          return true;
      }
      
        if(j> 0 and !visited[i][j-1] and board[i][j-1]==word[index+1] and search(i,j-1,index+1,word,board,visited))
      {
          return true;
      }
      
if(i < board.size()-1 and !visited[i+1][j] and board[i+1][j]==word[index+1] and search(i+1,j,index+1,word,board,visited))
      {
          return true;
      }
        if(j< board[0].size()-1 and !visited[i][j+1] and board[i][j+1]==word[index+1] and                                                                                                                  search(i,j+1,index+1,word,board,visited))
      
     {
          return true;
     }
        
        
      visited[i][j]=false;
        return false;
    } 
    
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),0));
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j] and search(i,j,0,word,board,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

*/