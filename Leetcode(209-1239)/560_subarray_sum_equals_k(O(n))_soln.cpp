class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0)
        {
            return 0;
        }
        int current_sum=0;
        int count=0;
        
        unordered_map<int,int>prefix_sum;
        
        for(int num : nums)
        {
            current_sum+=num;
            
            if(current_sum==k)
            {
                count+=1;
            }
            
        if(prefix_sum.find(current_sum-k)!=prefix_sum.end())//if already exists then include that also
        {
            count+=prefix_sum[current_sum-k];
        }
        if(prefix_sum.find(current_sum)!=prefix_sum.end())
        {
            prefix_sum[current_sum]+=1;
        }
        else
        {
            prefix_sum[current_sum]=1;
        }
        
    }   
        return count;   
    }
};