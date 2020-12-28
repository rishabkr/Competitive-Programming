class Solution {
public:
        Solution()
        {
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
        }
    int findUnsortedSubarray(vector<int>& nums) {
        
        int start=nums.size();
        int end=0;
        int res=1;
        vector<int>new_nums=nums;
        sort(new_nums.begin(),new_nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=new_nums[i])
            {
                start=min(start,i);
                end=max(end,i);
            }
        }
    return (end-start>=0)?end-start+1:0;
    }
};