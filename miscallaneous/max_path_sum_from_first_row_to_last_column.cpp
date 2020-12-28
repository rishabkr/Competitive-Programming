https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#
class Solution{
public:


    int maximumPath(int n, vector<vector<int>> mat)
    {
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(j >0 and j < n-1)
                {
                    mat[i][j]+=max({mat[i-1][j],mat[i-1][j+1],mat[i-1][j-1]});
                }
                
                else if(j > 0 )
                {
                    mat[i][j]+=max(mat[i-1][j],mat[i-1][j-1]);
                }
                else if(j < n-1 )
                {
                    mat[i][j]+=max(mat[i-1][j],mat[i-1][j+1]);
                }
                
            }
        }
        
        
        return *max_element(mat[n-1].begin(),mat[n-1].end());
    }
};