class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    //first transpose the matrix then reverese the rows
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
        for(int i=0;i<n;i++)
        {
         int l=0;
         int r=matrix[0].size()-1;
        while(l<r)
        {
            int temp=matrix[i][l];
            matrix[i][l]=matrix[i][r];
            matrix[i][r]=temp;
            l++;r--;
        }
        }
    }
};