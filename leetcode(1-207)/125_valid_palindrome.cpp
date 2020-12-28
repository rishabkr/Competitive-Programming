class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
        {
            return true;
        }
        string str="";
        for(int i=0;i<s.length();i++)
        {
            if(ispunct(s[i]) or s[i]==' ')
            {
                
                continue;
            }
            else
            {
                str.push_back(tolower(s[i]));
            }
        }
        int left=0;
        int right=str.length()-1;
        while(left<=right)
        {
            if(str[left]!=str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};