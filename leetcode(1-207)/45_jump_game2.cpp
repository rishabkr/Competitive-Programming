class Solution {
public:
    int jump(vector<int>& nums) {
        
        int num_jumps=0;
        int max_position=0;
        int max_reachable_till_now=0;
        
        
        for(int i=0 ; i <nums.size()-1; i++ )
        {
            max_reachable_till_now=max(max_reachable_till_now, i + nums[i]);
            
            if(max_position == i)
            {
                max_position=max_reachable_till_now;
                num_jumps++;
            }
        }
        return num_jumps;
    }
};



class Solution {
public:
    int jump(vector<int>& nums) {
        // this is the furthest element we can reach in 2 jumps
        int max_reach=0;
        
        //where we can reahch from current
        int current_reach=nums[0];
        
        //number of jumps
        int jumps=0;
        
        for(int i=1;i<nums.size();i++)
        {
               // if we can jump to the end from our current position, do it!
            if(current_reach >= nums.size()-1)
            {
                return jumps+1;
            }
            
            // if we find an element that beats our max reach, update it accordingly
            if(i + nums[i] > max_reach)
            {
                max_reach=i+nums[i];
            }
            
          // if we reached the limit of how far we can jump, that means we've fully
			 // examined all our choices. We can now jump once. `currentReach` becomes `maxReach`
            if(i >= current_reach)
            {
                jumps++;
                current_reach=max_reach;
            }
            
        }
        
    return jumps;
    }
};

/*We can take advantage of the fact that we never backtrack, as the array contains ONLY positive integers. Because we never backtrack and we can never get stuck, we would ALWAYS do the jump that gives us the most "reach" (the latest element we can get to). This lets us optimize A LOT.

so... currentReach would be the last element that we could reach in 1 jump, and maxReach would be the last element we can reach in 2 jumps.

When we reach currentReach, we have examined all the elements that we could possibly jump to,
and therefore we do a jump to the best one by setting currentReach to maxReach. (After 1 jump, the element we can reach in 2 jump is now the element we can reach in 1 jump)*/