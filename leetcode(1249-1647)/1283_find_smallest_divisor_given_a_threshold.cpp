class Solution {
public:
    
    long compute_sum(vector<int>&nums,int curr_threshold)
    {
        long sum=0;
        for(int num : nums)
        {
            sum+=(num/curr_threshold + (num%curr_threshold == 0 ? 0 : 1) ) ; //ceil
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int end=*max_element(nums.begin(),nums.end());
        
        // uncomment below for doubling the end implementation...
        // int end=2;
        // while(compute_sum(nums,end) > threshold)
        // {
        //     end=end*2;
        // }
        //int start=end/2;
 
        int start=1;
        
        while(start < end)
        {
            int mid=start+(end-start)/2;
            
            if(compute_sum(nums,mid) > threshold)
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return start;
    }
};