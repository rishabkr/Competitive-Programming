int Solution::isValidSudoku(const vector<string> &board) {

        unordered_map<string,int>mp;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                
                if(board[i][j]!='.')
                {
                    int box_num=(i/3)*3+j/3;
                    string element=to_string(board[i][j]);
                    
                    string row_idx="row"+to_string(i)+element;
                    string col_idx="col"+to_string(j)+element;
                    string box_idx="box"+to_string(box_num)+element;
                    
                    if(mp[row_idx]>0 or mp[col_idx]>0 or mp[box_idx]>0)
                    {
                        return false;
                    }
                    else
                    {
                        mp[row_idx]++;
                        mp[col_idx]++;
                        mp[box_idx]++;
                    }
                }
                
            }
        }
        return true;
}
