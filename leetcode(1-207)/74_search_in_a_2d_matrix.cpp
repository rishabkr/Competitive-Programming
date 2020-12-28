class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
        {
            return 0;
        }
        int i=0;
        int j=matrix[0].size()-1;
        
        while(i < matrix.size() and j >= 0)
        {
            if(matrix[i][j]==target)
            {
                return 1;
            }
            else if( target > matrix[i][j] )
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return 0;
    }
};

/*   bool found=false;
        for(int i=0;i<matrix.size();i++)
        {
            int low=0;
            int high=matrix[0].size()-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(matrix[i][mid]==target)
                {
                    return true;
                }
                else if(matrix[i][mid]>target)
                {
                    high=mid-1;
                }
                else if(matrix[i][mid]<target)
                {
                    low=mid+1;
                }
            }
        }
    return found;
    }*/