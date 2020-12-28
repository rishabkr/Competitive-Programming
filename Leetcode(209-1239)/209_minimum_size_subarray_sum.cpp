class Solution {
public:
    Solution()
    {
                ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {

        int res=INT_MAX;
        int left=0;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            while(curr_sum>=s)
            {
                res=min(res,i-left+1);
                curr_sum-=nums[left];
                left++;
            }
        }
        return res==INT_MAX?0:res;
    }
};