class Solution {
public:
        Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int max_len=0;
        mp[0]=-1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count+= -1;
            }
            else
            {
                count+= 1;
            }
            
            
            if(mp.find(count)!=mp.end())
            {
                max_len=max(max_len,i-mp[count]);
            }
            else
            {
                mp[count]=i;
            }
        }
        return max_len;
    }
};