class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        vector<int>res;
        //  for(int i=0;i<nums.size();i++)
        // {
        // if(hash.find(target-nums[i])!=hash.end()&&hash.find(target-nums[i])->second!=i)
        // {   res.push_back(i);
        //     res.push_back(hash.find(target-nums[i])->second);
        //     break;
        // }
        // }
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end()&&mp.find(target-nums[i])->second!=i)
            {
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                break;
            
            }
        }
        return res;
    }
};