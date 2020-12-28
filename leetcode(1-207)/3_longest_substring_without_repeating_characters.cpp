class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int max(int a,int b)
    {
     return a>b?a:b;   
    }
    int lengthOfLongestSubstring(string s) {
        int left_ptr=0;
        int right_ptr=0;
        int max_window_size=0;
        set<char>set;
        while(right_ptr<s.length())
        {
            if(set.find(s[right_ptr])==set.end())
            {
                set.emplace(s[right_ptr]);//can also use set.insert(s[right_ptr]);
                right_ptr++;
                max_window_size=max(max_window_size,set.size());
            }
            else
            {
                set.erase(s[left_ptr]);
                left_ptr++;
            }
        }
        return max_window_size;
    }
};