class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res=res^nums[i];
        }
        return res;
    }
};