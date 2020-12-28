class Solution {
public:
    
    int binary_search(vector<int> &nums,int target,bool find_start)
    {
        int res=-1;
        int start=0;
        int end=nums.size()-1;
        
        while(start <= end)
        {
            int mid=start + (end-start)/2;
            
            if(nums[mid]==target)
            {
                //dont return keep updating the occurance if found for both first and last
                if(find_start) //both parts merged in same code
                {
                 res=mid;
                 end=mid-1;
                }
                else
                {
                    res=mid;
                    start=mid+1;
                }
            }
            else if(nums[mid] < target)
            {
                start=mid+1;
            }
            else if(nums[mid] > target)
            {
                end=mid-1;
            }
            
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start=binary_search(nums,target,true);
        int end=binary_search(nums,target,false);
        
        return {start,end};
        
    }
};