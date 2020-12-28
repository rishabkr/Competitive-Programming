class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size())
    {
        return false;
    }
        bool flag=false;
        for(int i=0;i<matrix.size();i++)
{    int low=0;
     int high=matrix[i].size()-1;
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
        return flag;
}
    };