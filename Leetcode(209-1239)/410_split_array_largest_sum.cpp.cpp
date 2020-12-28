class Solution {
public:
    
    bool is_valid(vector<int>&nums,int m,int mid)
    {
        
        int total_sum=0;;
        int num_subarrays=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] >  mid)
            {
                return false;
            }
            if(total_sum + nums[i] <= mid)
            {
                total_sum+=nums[i];
            }
            else
            {
                num_subarrays++;
                total_sum=nums[i];
            }
        }
        num_subarrays++;
        
        return num_subarrays<=m;   
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int left=0;
        int right=int(1e9+1);
        
        while(left < right)
        {
            int mid=(left+right)/2;
            
            if(is_valid(nums,m,mid))
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};