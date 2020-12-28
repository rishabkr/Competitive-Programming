int Solution::jump(vector<int> &arr) {
    int n=arr.size();
    if(n<=1)
    {
        return 0;
    }
    
    if(arr[0]==0)
    {
        return -1;
    }
    
    int max_reach=arr[0];
    
    int num_steps_we_can_take=arr[0];
    
    int jump=1;
    int i=1;
    
    for(i=1;i<n;i++)
    {
        if(i==n-1)
        {
            return jump;
        }
        
        max_reach=max(max_reach,i+arr[i]);
        
        num_steps_we_can_take--;
        
         // If no further steps left 
        if(num_steps_we_can_take==0)
        {
            jump++;
            
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i>=max_reach)
            {
                return -1;
            }
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            num_steps_we_can_take=max_reach-i;
        }
    }
    return -1;
}
/*If no more steps are remaining (i.e. steps=0, then we must
have used a jump. Therefore increase jump. Since we know that
it is possible somehow to reach maxReach, we again initialize
the steps to the number of steps to reach maxReach from position
i. But before re-initializing step, we also check whether a step
is becoming zero or negative. In this case, It is not possible to reach further.*/
