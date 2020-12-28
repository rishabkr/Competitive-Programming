class Solution {
public:
    vector<vector<int>>res;
    void backtrack(vector<int>&nums,vector<int>&vec)
    {
        if(vec.size()==nums.size())
        {
            res.push_back(vec);
            return;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(find(vec.begin(),vec.end(),nums[i])!=vec.end())
                {
                    continue;
                }
                vec.push_back(nums[i]);
                backtrack(nums,vec);
                vec.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        backtrack(nums,ans);
        return res;
    }
};