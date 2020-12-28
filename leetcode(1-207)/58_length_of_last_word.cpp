class Solution {
public:
    int lengthOfLastWord(string s) {
        
    int n=s.length();
    int result=0;
        
    while(n>0)
    {
        if(s[--n]!=' ')
        {
            result++;
        }
        else if(result > 0)
        {
            return result;
        }
    }
        return result;
        
//OR        
//         stringstream ss(s);
        
//         string word;
//         while(ss>>word);
//         return word.length();
    }
};