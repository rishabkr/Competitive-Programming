class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     
        unordered_map<long long int,long long int>mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        int longest_streak=0;
        
        for(long long int num : nums)
        {
            if(mp.find(num-1)==mp.end())
            {
                long long int current_num=num;
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
};