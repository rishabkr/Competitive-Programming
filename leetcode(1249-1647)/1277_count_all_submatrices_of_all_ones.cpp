class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]>0 and i>0 and j>0)
                {
                    matrix[i][j]=1+min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
                }
                res+=matrix[i][j];
            }
        }
        return res;
    }
};