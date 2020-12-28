class Solution {
public:
    
void print(vector<int>&nums,vector<int>&res,int i)
{
    cout<<"res \n";
    for(auto it : res)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    
    cout<<i<<"\n";
    cout<<"nums \n";
    for(auto it : nums)
    {
        cout<<it<<" ";
    }
    cout<<"\n";

}
    
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            int index=abs(nums[i])-1;
            if(nums[index]<0)
            {
                res.push_back(index+1);
            }
            
            nums[index]=-nums[index];
            //print(nums,res,i);
        }
        
        return res;
    }
};