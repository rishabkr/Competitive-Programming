class Solution {
public:
    
    int count_of_subset_sum(vector<int>&nums,int sum)
    {
        int n=nums.size();
        int subset_sum[n+1][sum+1];
        
        
        for(int j=0;j<=sum;j++)
        {
            subset_sum[0][j]=0;
        }
        
        subset_sum[0][0]=1;
        
        for(int i=1;i<n+1;++i)
        if(nums[i-1]==0)
        {
            // For sum 0, Empty subset + subset made by 0 element
            // By multiplying pow(2,cnt), it will consider all the subsets of 0 which was               
			// not considered earlier.
            subset_sum[i][0]=2*subset_sum[i-1][0]; 
        }
                
        else
        {
             subset_sum[i][0]=subset_sum[i-1][0];
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
              
                if(nums[i-1] <= j)
                {
                    subset_sum[i][j]=subset_sum[i-1][j] + subset_sum[i-1][j-nums[i-1]];
                }
                else if(nums[i-1]>j)
                {
                    subset_sum[i][j]=subset_sum[i-1][j];
                }
                
            }
            
        }
        return subset_sum[n][sum];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto num : nums)
        {
            sum+=num;
        }
        
        if(sum <  S or (S+sum)%2!=0)
        {
            return 0;
        }
        
        int required_sum=(sum+S)/2;
        return count_of_subset_sum(nums,required_sum);
    }
};