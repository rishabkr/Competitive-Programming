class Solution {
public:    
    
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        if(!nums.size())
        {
            return res;
        }
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0]=nums[0];
        right[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)
        {
            left[i]=left[i-1]*nums[i];
        }
        for(int i=nums.size()-2;i>-1;i--)
        {
            right[i]=nums[i]*right[i+1];
        }
        res[0]=right[1];
        res[nums.size()-1]=left[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++)
        {
            res[i]=left[i-1]*right[i+1];
        }

return res;        
    }
};