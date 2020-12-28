class Solution {
public:
    
    void dfs(vector<vector<int>>&res,vector<int>&nums,vector<int>&temp,int index,int target)
    {
        if(target < 0)
        {
            return;
        }
        
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            if(i>index and nums[i]==nums[i-1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            dfs(res,nums,temp,i+1,target-nums[i]);
            temp.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        if(!candidates.size())
        {
            return {{}};
        }
        
        vector<vector<int>>res;
        vector<int>temp;
        dfs(res,candidates,temp,0,target);
        return res;
    }
};