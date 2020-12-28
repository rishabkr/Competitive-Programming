class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(!nums.size())return 0;
        vector<int>dp(nums.size()+1);
        dp[0]=0;
        dp[1]=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            dp[i+1]=max(dp[i],nums[i]+dp[i-1]);
        }
        
        return dp[nums.size()];
    }
};


//recursive method bwelow 56/69 cases then tle
// class Solution {
// public:
    
//     int recursive_rob(vector<int>&nums,int n)
//     {
//         if(n<=0)
//         {
//             return 0;
//         }
        
//         if(n==1)
//         {
//             return nums[0];
//         }
        
//         return max(nums[n-1] + recursive_rob(nums,n-2),recursive_rob(nums,n-1));
//     }
    
//     int rob(vector<int>& nums) {
//         if(nums.size()==0)
//         {
//             return 0;
//         }
        
//         if(nums.size() ==1)
//         {
//             return  nums[0];
//         }
        
//         if(nums.size()==2)
//         {
//             return nums[0]>nums[1]? nums[0]:nums[1];
//         }
//         int n=nums.size();
//         return max(nums[n-1] + recursive_rob(nums,n-2),recursive_rob(nums,n-1));
//     }
// };