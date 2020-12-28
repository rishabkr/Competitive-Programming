class Solution {
public:
    
    void dfs(vector<int>&nums,vector<vector<int>>&res,int target,int index,vector<int>&temp)
    {
        if(target < 0)
        {
            return ;
        }
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        
        for(auto i=index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            dfs(nums,res,target-nums[i],i,temp);
            temp.pop_back();
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<vector<int>>res;
        if(!candidate.size())
        {
            return res;
        }
        vector<int>temp;
        dfs(candidate,res,target,0,temp);
        
        return res;
    }
};