class Solution {
public:
    int binary_search(int low,int high,vector<int>&nums)
    {
        if(low==high)
        {
            return low;
        }
        int mid=low+(high-low)/2;
        if(nums[mid]>nums[mid+1])
        {
            return binary_search(low,mid,nums);
        }
        return binary_search(mid+1,high,nums);
    }
    
    int findPeakElement(vector<int>& nums) {
       return binary_search(0,nums.size()-1,nums);
    }
};