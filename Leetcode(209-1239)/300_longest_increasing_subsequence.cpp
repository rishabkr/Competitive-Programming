class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
        {
            return 0;
        }
        vector<int>lis(nums.size(),1);
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            res=max(res,lis[i]);
        }
        // for(auto i:lis)
        // {
        //     cout<<i<<" ";
        // }
        return res;
    }
};