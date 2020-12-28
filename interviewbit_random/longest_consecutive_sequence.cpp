int Solution::longestConsecutive(const vector<int> &nums) {
    
    unordered_map<int,int>mp;
    int longest_streak=0;
    for(int num : nums)
    {
        mp[num]++;
    }
    for(int num : nums)
    {
        
        if(mp.find(num-1)==mp.end())
        {
            int current_num=num;
            int current_streak=1;
        
            while(mp.find(current_num+1)!=mp.end())
            {
                current_num++;
                current_streak++;
            }
        
            longest_streak=max(longest_streak,current_streak);
        }
        
    }
    return longest_streak;
    
}
