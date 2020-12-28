class Solution {
public:
    
    string longestPalindrome(string s) {
        
        if(s.length() <= 1)
        {
            return s;
        }
        
        int max_length=1;
        int start=0;
        int end=0;
        int n=s.length();
        
        for(int i=0;i<n; i++)
        {
            int left=i;int right=i;
            
            while(left>=0 and right<n)
            {
                if(s[left] == s[right])
                {
                    left--;right++;
                }
                else
                {
                    break;
                }
            }
            if(right-left-1 > max_length)
            {
                max_length=right-left-1;
                start=left+1;
                end=right-1;
            }
        }
        
        for(int i=0;i<n; i++)
        {
            int left=i;int right=i+1;
            
            while(left>=0 and right<n)
            {
                if(s[left] == s[right])
                {
                    left--;right++;
                }
                else
                {
                    break;
                }
            }
            if(right-left-1 > max_length)
            {
                max_length=right-left-1;
                start=left+1;
                end=right-1;
            }
        }

        return s.substr(start,end-start+1);
    }
};