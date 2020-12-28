class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int>test_t_0(nums.begin(),nums.end());
        
        if(t==0 and test_t_0.size()==nums.size())
        {
            return false;
        }
        
       //O(nk)
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<i+1+k;j++)
            {
                if(j>=n)
                {
                    break;
                }
                
                if(abs((long long)nums[i]-nums[j])<=t)//long long to prevent overflow
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};