int Solution::solve(vector<int> &nums, int k) {
    int curr_xor=0;
    map<int,int>mp;
    
    int count=0;
    
    //if y^k=xr
    //y=xr^k

    for(auto num : nums)
    {
        curr_xor^=num;
        
        if(curr_xor==k)
        {
            count+=1;
        }
        
        if(mp.find(curr_xor ^ k)!=mp.end())
        {
            count+=mp[curr_xor^k];
        }
        mp[curr_xor]+=1;
    }
    return count;
}
