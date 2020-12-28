class Solution {
public:
    
    unordered_map<string,vector<string>>dp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(dp.find(s)!=dp.end())
        {
            return dp[s];
        }
        vector<string>res;
        //1.
        for(string word : wordDict)
        {
            //2 if the whole word is equal to the string
            if(s.substr(0,word.length())==word)
            {
                if(word.length() == s.length())
                {
                    res.push_back(word);
                }
                else
                {
                    vector<string>temp=wordBreak(s.substr(word.length()),wordDict);
                    
                    for(string str : temp)
                    {
                        res.push_back(word+ " " + str);
                    }
                }
            
            }
            
        }
        dp[s]=res;
        return res;
    }
};