class Solution {
public:
    
    int get_shift_count(vector<vector<int>>& A,vector<vector<int>>& B)
    {
        int count=0;
        
        int n=A.size();
        
        for(int x_shift=0;x_shift<n;x_shift++)
        {
            for(int y_shift=0;y_shift<n;y_shift++)
            {
                int current_count=0;
                
                for(int i=y_shift;i<n;i++)
                {
                    for(int j=x_shift;j<n;j++)
                    {
                        if(A[i][j]==1 and B[i-y_shift][j-x_shift]==1)
                        {
                                current_count+=1;
                            
                        }
                    }
                    
                }
                count=max(count,current_count);
                
            }
        }
        
        return count;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(get_shift_count(A,B),get_shift_count(B,A));
    }
};