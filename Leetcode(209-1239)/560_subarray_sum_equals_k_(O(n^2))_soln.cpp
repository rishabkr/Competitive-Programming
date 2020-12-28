class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefix[nums.size()+1];
        prefix[0]=0;
        for(int i=1;i<=nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<=nums.size();j++)
            {
                //cout<<prefix[j]<<" "<<prefix[i]<<" "<<count<<endl;
                if((prefix[j]-prefix[i])==k)
                {
                    count+=1;
            
                }
            }
        }
        
    return count;
    }
};