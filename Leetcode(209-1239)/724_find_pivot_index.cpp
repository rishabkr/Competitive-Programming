class Solution {
public:
    
    void print(vector<int>&arr)
    {
        cout<<endl;
        for(auto i:arr)
        {
            cout<<i<<" ";
        }
    }
    int pivotIndex(vector<int>& nums) {
        
        if(!nums.size())
        {
            return -1;
        }
        
        
        int n=nums.size();
        int total_sum=0;
        
        for(int i=0;i<n;i++)
        {
            total_sum+=nums[i];
        }
        
        int left_sum=0;
        for(int i=0;i<n;i++)
        {
            if(left_sum == total_sum-nums[i])
            {
                return i;
            }
            left_sum+=nums[i];
            total_sum-=nums[i];
        }
        
        return -1;
    }
};