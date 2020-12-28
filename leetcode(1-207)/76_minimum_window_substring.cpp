class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    string minWindow(string s, string t) {
    int s_hash[256]={0};
        int t_hash[256]={0};
    
        for(char c:t)
        {
            t_hash[c]++;
        }
        
        
        int left=0;
        int right=0;
        
        int count=0;
        int min_len=INT_MAX;
        int start_idx=-1;
        
        
        while(right<s.length())
        {
            s_hash[s[right]]++;
            // if this char is present in string t && make sure this char count in string s doesn't exceed string t (to avoid increment count for duplicates)
            
            if(t_hash[s[right]]!=0 and s_hash[s[right]]<=t_hash[s[right]])
            {
                count++;
            }
            // check if count is equal to t's length (we found a substring in s which satisfies condition)
            while(count==t.length())
            {
                if(min_len > (right-left+1))
                {
                    min_len=right-left+1;
                    start_idx=left;
                }
                
                // Move left slider till count goes less than t.length()
                if(s_hash[s[left]]!=0 and s_hash[s[left]]==t_hash[s[left]])
                {
                    count--;
                }
                s_hash[s[left]]--;
                left++;
            }
            right++;
        }
        
        if(start_idx==-1)
        {
            return "";
        }
        return s.substr(start_idx,min_len);
        
        
    }
};