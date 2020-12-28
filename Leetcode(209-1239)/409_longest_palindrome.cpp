class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> counts;
        
        for(auto c : s)
        {
            counts[c]++;
        }
        
        int res=0;
        bool odd_found=0;
        for(auto it : counts)
        {
            if(it.second%2==0)
            {
                res+=it.second;
            }
            else
            {
                odd_found=1;
                res+=it.second-1;
            }
        }
        if(odd_found)
        {
            res++;
        }
        
        return res;
    }
};