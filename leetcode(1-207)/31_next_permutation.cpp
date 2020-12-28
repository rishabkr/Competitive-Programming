class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int first_index,second_index;
        
        for(first_index=nums.size()-2;first_index >=0 ; first_index--)
        {
            if(nums[first_index] < nums[first_index+1])
            {
                break;
            }
        }
        //if no index_was_found
        if(first_index < 0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(second_index=nums.size()-1;second_index >  first_index; second_index--)
            {
                if(nums[second_index] > nums[first_index])
                {
                    break;
                }
            }
            swap(nums[first_index],nums[second_index]);
            reverse(nums.begin()+first_index+1,nums.end());
        }
        
    }
};