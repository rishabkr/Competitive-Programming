class Solution {
public:
    
    bool subset_sum(vector<int>&nums,int sum)
    {
        int n=nums.size();
        
        bool dp[n+1][sum+1];
        
        for(int j=0;j<=sum;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num : nums)
        {
            sum+=num;
        }
        
        if(sum%2!=0)
        {
            return 0;
        }
    return subset_sum(nums,sum/2);

    }
};