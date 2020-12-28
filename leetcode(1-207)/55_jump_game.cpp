
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_good_index=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i] >= last_good_index)
            {
                last_good_index=i;
            }
        }
        return last_good_index==0;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int max_reachable_till_now=0;
        int position_reached=0;
        
        for(int i=0;i< nums.size()-1 ;i++ )
        {
            
            max_reachable_till_now= max(max_reachable_till_now ,  i + nums[i]);
            
            
            if(position_reached == i)
            {
                position_reached=max_reachable_till_now;
            }
        }
        if (position_reached < nums.size()-1)
        {
            return false;
        }
    return true;
    }
    
    
};